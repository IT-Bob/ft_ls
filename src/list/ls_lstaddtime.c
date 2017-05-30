/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstaddtime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:23:40 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/30 12:19:49 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** ls_lstaddalpha() trie les éléments par date de dernière modification en se
** basant sur les informations de la structure stat, contenue dans t_elem.
*/

t_elem	*ls_lstaddtime(t_elem **alst, t_elem *new)
{
	t_elem *lst;
	t_elem *prev;
	t_elem *head;

	head = (new ? *alst : NULL);
	if (new)
	{
		lst = *alst;
		prev = NULL;
		if (!lst)
			return (new);
		while (lst && ((new->stat.st_mtime < lst->stat.st_mtime) ||
						((new->stat.st_mtime == lst->stat.st_mtime) &&
						ft_strcmp(new->name, lst->name) > 0)))
		{
			prev = lst;
			lst = lst->next;
		}
		if (prev)
			prev->next = new;
		else
			head = new;
		new->next = lst;
	}
	return (head);
}
