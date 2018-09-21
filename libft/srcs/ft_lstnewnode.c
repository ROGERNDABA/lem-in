/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 08:57:38 by rmdaba            #+#    #+#             */
/*   Updated: 2018/08/28 08:59:45 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnewnode(void *data)
{
	t_list		*newelem;

	newelem = (t_list*)malloc(sizeof(t_list));
	if (newelem)
	{
		newelem->data = data;
		newelem->next = NULL;
	}
	return (newelem);
}
