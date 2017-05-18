/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstaddalpha.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:23:40 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/18 14:22:32 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** ls_lstaddalpha() effectue un tri par insertion de l'élément new dans la liste
** alst. La comparaison est faite sur le champ name de la structure t_elem.
*/

t_elem	*ls_lstaddalpha(t_elem **alst, t_elem *new)
{
	t_elem *lst;
	t_elem *prev;
	t_elem *head;

	if (new)
	{
		head = *alst;
		lst = *alst;
		prev = NULL;
		if (!lst)
			return (new);
		while (lst && (ft_strcmp(new->path, lst->path) > 0))
		{
			prev = lst;
			lst = lst->next;
		}
		if (prev)
			prev->next = new;
		else
			head = new;
		new->next = lst;
		return (head);
	}
	return (NULL);
}
