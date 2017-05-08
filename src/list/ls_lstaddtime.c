/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstaddtime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:23:40 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/05 17:35:58 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

/*
** ls_lstaddalpha() trie les éléments par date de dernière modification en se
** basant sur le champ st_ctime de la structure stat contenue dans t_elem.
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
		while(lst && (new->stat.st_ctime < lst->stat.st_ctime))
		{
			prev = lst;
			lst = lst->next;
		}
		if (lst && (new->stat.st_ctime == lst->stat.st_ctime))
		{
			if (prev)
				prev->next = ls_lstaddalpha(&prev->next, new);
			else
				head = new;
		}
		else if (prev)
			prev->next = new;
		else
			head = new;
		new->next = lst;
		return (head);
	}
	return (NULL);
}
