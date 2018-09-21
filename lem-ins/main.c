#include "libft.h"

int main(int ac, char **av)
{
	char	*line;
	if (ac > 1)
	{
		if (open(av, 0))
			printf("yes\n");
	}
}
