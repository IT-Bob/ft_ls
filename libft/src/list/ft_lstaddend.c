/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 12:14:25 by aguerin           #+#    #+#             */
/*   Updated: 2017/01/30 12:14:49 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Ajoute un maillon en fin de liste
*/

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*lst;

	lst = *alst;
	if (!lst)
		*alst = new;
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
}
