/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_direc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:52:55 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/12 13:31:09 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static void	lstiter_reverse(t_elem *lst, t_ls *ls, void (*f)(t_elem *, t_ls *))
{
	if (lst)
	{
		lstiter_reverse(lst->next, ls, f);
		if (lst->next)
			ft_putchar('\n');
		f(lst, ls);
	}
}

static void	lstiter(t_elem *lst, t_ls *ls, void (*f)(t_elem *, t_ls *))
{
	while (lst)
	{
		f(lst, ls);
		lst = lst->next;
		if (lst)
			ft_putchar('\n');
	}
}

void		ls_direc(t_elem **direc, t_ls *ls)
{
	if (*direc)
	{
		if (ls && ls->nb_files)
			ft_putchar('\n');
		if (ls && ls->flags[3])
			lstiter_reverse(*direc, ls, &print_directory);
		else
			lstiter(*direc, ls, &print_directory);
		ls_lstdel(direc);
	}
}
