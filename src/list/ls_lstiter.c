/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:55:46 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/09 17:05:03 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** ls_lstiter() applique la fonction f sur chaque maillon de la liste lst.
*/

void	ls_lstiter(t_elem *lst, void(*f)(t_elem *elem))
{
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
