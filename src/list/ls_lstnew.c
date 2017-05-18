/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:23:40 by aguerin           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/05/18 17:06:36 by aguerin          ###   ########.fr       */
=======
/*   Updated: 2017/05/18 14:24:16 by aguerin          ###   ########.fr       */
>>>>>>> 0698bc3a845cd08614e7058f9f5f98619a24c150
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

/*
** ls_lstnew() alloue la mémoire et initialise la structure pour la liste de ls.
*/

<<<<<<< HEAD
t_elem	*ls_lstnew(char *name, char *path, struct stat stat)
=======
t_elem	*ls_lstnew(char *path, struct stat stat)
>>>>>>> 0698bc3a845cd08614e7058f9f5f98619a24c150
{
	t_elem	*element;

	if ((element = (t_elem*)ft_memalloc(sizeof(t_elem))))
	{
<<<<<<< HEAD
		if ((element->name = (name ? ft_strnew(ft_strlen(name)) : NULL)))
			element->name = ft_strcpy(element->name, name);
=======
>>>>>>> 0698bc3a845cd08614e7058f9f5f98619a24c150
		if ((element->path = (path ? ft_strnew(ft_strlen(path)) : NULL)))
			element->path = ft_strcpy(element->path, path);
		element->stat = stat;
		element->next = NULL;
	}
	return (element);
}
