/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstiter_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:32:55 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/09 19:36:48 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_lstiter_reverse(t_elem *list, void (*f)(t_elem*))
{
	if (list)
	{
		ls_lstiter_reverse(list->next, f);
		f(list);
	}
}
