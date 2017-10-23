/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddapha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 13:52:07 by aguerin           #+#    #+#             */
/*   Updated: 2017/04/21 13:52:09 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
** ft_lstaddalpha() ajoute un élément new dans la liste alst en respectant
** l'ordre ASCII (du champ 'content' de t_list) et renvoie la tête de liste.
** La fonction renvoie NULL si new est nul.
*/

t_list	*ft_lstaddalpha(t_list **alst, t_list *new)
{
	t_list	*lst;
	t_list	*prev;
	t_list	*head;

	if (new)
	{
		head = *alst;
		lst = *alst;
		prev = NULL;
		if (!lst)
			return (new);
		while (lst && (ft_strcmp(new->content, lst->content) > 0))
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
