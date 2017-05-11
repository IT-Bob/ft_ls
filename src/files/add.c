/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:53:21 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/11 15:54:55 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

t_elem	*add_files(t_elem *files, char *name, t_ls *ls, struct stat s)
{
	if (ls && ls->flags[4])
		files = ls_lstaddtime(&files, ls_lstnew(name, s));
	else
		files = ls_lstaddalpha(&files, ls_lstnew(name, s));
	if (ls)
		ls->nb_files = 1;
	return (files);
}
