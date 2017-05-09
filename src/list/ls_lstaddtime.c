/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstaddtime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:23:40 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/09 20:00:57 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

/*
** ls_lstaddalpha() trie les éléments par date de dernière modification en se
** basant sur les informations de la structure stat, contenue dans t_elem.
*/

t_elem	*ls_lstaddtime(t_elem **alst, t_elem *new)
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
		while (lst && ((new->stat.st_mtime < lst->stat.st_mtime) ||
			((new->stat.st_mtime == lst->stat.st_mtime) && ft_strcmp(new->name, lst->name) > 0)))/*&&
			(new->stat.st_mtimespec.tv_nsec < new->stat.st_mtimespec.tv_nsec)*/
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
