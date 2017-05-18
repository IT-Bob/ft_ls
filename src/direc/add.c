/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:51:50 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/18 14:14:30 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem	*add_direc(t_elem *direc, char *path, t_ls *ls, struct stat s)
{
	if (ls->flags[4])
		direc = ls_lstaddtime(&direc, ls_lstnew(path, s));
	else
		direc = ls_lstaddalpha(&direc, ls_lstnew(path, s));
	if (ls)
		ls->nb_direc += 1;
	return (direc);
}
