#include "libft.h"

int		only_digit(char *string)
{
	int i;

	i = -1;
	while(string[++i])
		if (!ft_isdigit(string[i]))
			return (0);
	return (1);
}

void	ft_pushback(t_dlist **list, char *value, int n)
{
	t_dlist		*new_node;
	t_dlist		*last;

	last = *list;
	new_node = (t_dlist *)malloc(sizeof(t_dlist));
	new_node->data = value;
	new_node->data_size = n;
	new_node->next = NULL;
	if (*list == NULL)
	{
		new_node->prev = NULL;
		new_node->data_size = n;
		*list = new_node;
		return ; 
	}
	while (last->next != NULL) 
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
	return ;
}

typedef struct s_in
{
	char		*line;
	int			n_ants;
	int			n_rooms;
	char		**links;
	t_dlist		*room;
}				t_in;

void	get_number_of_ants(t_in *farm, int fd, char *line)
{
	int track;

	track = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!ft_strcmp(line, "##start"))
			track = 1;
		if (!track && only_digit(line))
		{
			farm->n_ants = ft_atoi(line);
			ft_strdel(&line);
			break;
		}
		ft_strdel(&line);
	}
}

t_in		*make_farm(void)
{
	t_in	*farm;

	farm = (t_in *)malloc(sizeof(t_in));
	farm->n_ants = 0;
	farm->n_rooms = 0;
	farm->room = NULL;
	farm->line = NULL;
	return (farm);
}

// void	get_links(t_in *farm, char *line)
// {
// 	char	**split;

// 	farm->links = (int **)malloc(sizeof(int *));
// 	while (line != NULL)
// 	{

// 	}
// }

void	get_rooms(int fd, t_in *farm)
{
	int track;

	track = 0;
	get_number_of_ants(farm, fd, farm->line);
	while (get_next_line(fd, &farm->line) > 0 && !ft_strchr(farm->line, '-'))
	{
		track = !ft_strcmp(farm->line, "##start") ? 1 : track;
		track = !ft_strcmp(farm->line, "##end") ? 2 : track;
		if (track == 1 && !ft_strchr(farm->line, '#') && !(track = 0))
			ft_pushback(&farm->room, ft_strtok(farm->line, " "), 1);
		else if (track == 2 && !ft_strchr(farm->line, '#') && !(track = 0))
			ft_pushback(&farm->room, ft_strtok(farm->line, " "), 2);
		else if (!ft_strchr(farm->line, '#'))
			ft_pushback(&farm->room, ft_strtok(farm->line, " "), 0);
		else
			ft_strdel(&farm->line);
	}
}

int main(int ac, char **av)
{
	t_in *farm;

	int fd;

	fd = 0;
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			printf(RED"INVALID FILE, GIVE A REAL FILE MAN\n"DEFAULT);
		farm = make_farm();
		get_rooms(fd, farm);
		t_dlist *tmp = farm->room;
		printf("number of ants  %d\n", farm->n_ants);
		while (tmp != NULL)
		{
			if (tmp->data_size == 1)
				printf(GREEN"begin room -> %s\n"DEFAULT, tmp->data);
			else if (tmp->data_size == 2)
				printf(RED"end room -> %s\n"DEFAULT, tmp->data);
			else
				printf("%s\n", tmp->data);
			tmp = tmp->next;
		}
		while (farm->room != NULL)
			ft_dlstremovenode(&farm->room);
		free(farm);
	}
	while(1);
	close(fd);
}
