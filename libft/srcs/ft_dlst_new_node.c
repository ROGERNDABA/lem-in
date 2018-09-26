/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_new_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:31:01 by rmdaba            #+#    #+#             */
/*   Updated: 2018/09/21 12:33:20 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlst_new_node(char *data)
{
	t_dlist *rooms;

	rooms = (t_dlist *)malloc(sizeof(t_dlist));
	if (rooms)
	{
		rooms->data = data;
		rooms->data_size = 0;
		rooms->next = NULL;
		rooms->prev = NULL;
	}
	return (rooms);
}
