/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:53:21 by aguerin           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/05/18 17:02:11 by aguerin          ###   ########.fr       */
=======
/*   Updated: 2017/05/18 14:14:45 by aguerin          ###   ########.fr       */
>>>>>>> 0698bc3a845cd08614e7058f9f5f98619a24c150
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem	*add_files(t_elem *files, char *path, t_ls *ls, struct stat s)
{
	if (ls && ls->flags[4])
<<<<<<< HEAD
		files = ls_lstaddtime(&files, ls_lstnew(name, NULL, s));
	else
		files = ls_lstaddalpha(&files, ls_lstnew(name, NULL, s));
=======
		files = ls_lstaddtime(&files, ls_lstnew(path, s));
	else
		files = ls_lstaddalpha(&files, ls_lstnew(path, s));
>>>>>>> 0698bc3a845cd08614e7058f9f5f98619a24c150
	if (ls)
		ls->nb_files = 1;
	return (files);
}

t_elem	*add_files_path(t_elem *f, char *path, t_ls *ls, struct stat s)
{
	if (ls && ls->flags[4])
		f = ls_lstaddtime(&f, ls_lstnew(just_name(path), path, s));
	else
		f = ls_lstaddalpha(&f, ls_lstnew(just_name(path), path, s));
	if (ls)
		ls->nb_files = 1;
	return (f);
}
