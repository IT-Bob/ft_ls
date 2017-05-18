/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:51:50 by aguerin           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/05/18 17:03:40 by aguerin          ###   ########.fr       */
=======
/*   Updated: 2017/05/18 14:14:30 by aguerin          ###   ########.fr       */
>>>>>>> 0698bc3a845cd08614e7058f9f5f98619a24c150
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem	*add_direc(t_elem *direc, char *path, t_ls *ls, struct stat s)
{
	if (ls->flags[4])
<<<<<<< HEAD
		direc = ls_lstaddtime(&direc, ls_lstnew(name, NULL, s));
	else
		direc = ls_lstaddalpha(&direc, ls_lstnew(name, NULL, s));
=======
		direc = ls_lstaddtime(&direc, ls_lstnew(path, s));
	else
		direc = ls_lstaddalpha(&direc, ls_lstnew(path, s));
>>>>>>> 0698bc3a845cd08614e7058f9f5f98619a24c150
	if (ls)
		ls->nb_direc += 1;
	return (direc);
}
