/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:38:07 by aguerin           #+#    #+#             */
/*   Updated: 2017/06/21 14:27:30 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

/*
** ft_lstnew() alloue la mémoire pour un maillon t_list
** et y copie les paramètres donnés.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = (t_list*)malloc(sizeof(t_list));
	if (list)
	{
		if (!content)
		{
			list->content = NULL;
			list->content_size = 0;
		}
		else
		{
			if (!(list->content = malloc(sizeof(content) * content_size)))
				return (NULL);
			ft_memcpy(list->content, content, content_size);
			list->content_size = content_size;
		}
		list->next = NULL;
		return (list);
	}
	return (NULL);
}
