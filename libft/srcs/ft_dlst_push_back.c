/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:14:30 by rmdaba            #+#    #+#             */
/*   Updated: 2018/09/22 18:11:11 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlst_push_back(t_dlist **list, char *value)
{
	t_dlist		*new_node;
	t_dlist		*last;

	last = *list;
	new_node = (t_dlist *)malloc(sizeof(t_dlist));
	new_node->data = ft_strdup(value);
	new_node->data_size = 0;
	new_node->next = NULL;
	if (*list == NULL)
	{
		new_node->prev = NULL;
		new_node->data_size = 0;
		*list = new_node;
		return ; 
	}
	while (last->next != NULL) 
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
	return ;
}
