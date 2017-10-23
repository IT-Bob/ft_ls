/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelonejoin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 09:58:40 by aguerin           #+#    #+#             */
/*   Updated: 2017/01/20 09:58:42 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Supprime un élément de la liste
** et fait le lien entre l'élément précédent et le suivant.
*/

t_list		*ft_lstdelonejoin(int content_size, t_list *list)
{
	t_list *new;

	new = list;
	if (new)
	{
		list = list->next;
		if (new->content_size && new->content_size == (size_t)content_size)
			free(new->content);
		free(new);
		new = NULL;
	}
	return (list);
}
