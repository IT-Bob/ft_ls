/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:30:39 by aguerin           #+#    #+#             */
/*   Updated: 2017/02/01 11:07:15 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Ajoute un élément en fin de liste.
** Si la liste n'existe pas, celle-ci est créée.
*/

t_list	*ft_lstaddnew(void const *content, size_t content_size, t_list *list)
{
	t_list	*new;

	if (!list)
		list = ft_lstnew(content, content_size);
	else
	{
		new = ft_lstnew(content, content_size);
		ft_lstaddend(&list, new);
	}
	return (list);
}
