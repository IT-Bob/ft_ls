/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:51:50 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/19 11:11:09 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem	*add_direc(t_elem *direc, char *name, t_ls *ls, struct stat s)
{
	if (ls->flags[4])
		direc = ls_lstaddtime(&direc, ls_lstnew(name, NULL, s, ls));
	else
		direc = ls_lstaddalpha(&direc, ls_lstnew(name, NULL, s, ls));
	if (ls)
		ls->nb_direc += 1;
	return (direc);
}
