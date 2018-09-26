/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:57:17 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/24 14:28:01 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*find_fd(int fd, t_gnl **lst)
{
	t_gnl *data;

	data = *lst;
	while (data)
	{
		if (data->fd == fd)
		{
			if (!(data->data))
				data->data = ft_strnew(0);
			return (data);
		}
		data = data->next;
	}
	if (!(data = malloc(sizeof(*data))))
		return (NULL);
	data->fd = fd;
	data->data = ft_strnew(0);
	data->next = *lst;
	*lst = data;
	return (data);
}

static int		fd_read_in(int fd, t_gnl *lst)
{
	char	str[BUFF_SIZE + 1];
	char	*temp;
	int		ret;

	while ((ret = read(fd, str, BUFF_SIZE)) > 0)
	{
		str[ret] = '\0';
		temp = lst->data;
		if (!(lst->data = ft_strjoin(lst->data, str)))
			return (-1);
		ft_strdel(&temp);
		if (ft_strchr(lst->data, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	if (ft_strlen(lst->data) == 0)
		return (0);
	return (1);
}

static int		populate_line(t_gnl *current, char **line)
{
	char	*tmp;
	char	*ptr;

	if (*(current->data))
	{
		if (!(ptr = ft_strchr(current->data, '\n')))
		{
			*line = current->data;
			current->data = NULL;
		}
		else
		{
			*line = ft_strnew(ptr - current->data);
			ft_memcpy(*line, current->data, ptr - current->data);
			tmp = current->data;
			current->data = ft_strdup(++ptr);
			ft_strdel(&tmp);
		}
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static	t_gnl	*data;
	t_gnl			*current;
	int				ans;

	if (!line || BUFF_SIZE <= 0 || fd < 0 || (ans = read(fd, "", 0)) < 0)
		return (-1);
	current = find_fd(fd, &data);
	if (!(ft_strchr(current->data, '\n')))
	{
		ans = fd_read_in(fd, current);
		if (ans < 0)
			return (-1);
		if (ans == 0)
			return (0);
	}
	return (populate_line(current, line) > 0 ? 1 : 0);
}
