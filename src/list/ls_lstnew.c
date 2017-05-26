/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:23:40 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/26 13:49:42 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <sys/types.h>

/*
** ls_lstnew() alloue la mémoire et initialise la structure pour la liste de ls.
*/


// À PROTEGER
void long_flag(t_elem *elem, struct stat stat)
{
	char	*date;
	struct passwd	*pwd;
	struct group	*grp;

	date = NULL;
	elem->link = stat.st_nlink;
	elem->size = stat.st_size;
	if (!(pwd = getpwuid(stat.st_uid)))
		perror(NAME);
	else
	{
		elem->user = ft_strnew(ft_strlen(pwd->pw_name));
		elem->user = ft_strcpy(elem->user, pwd->pw_name);
	}
	if (!(grp = getgrgid(stat.st_gid)))
		perror(NAME);
	else
	{
		elem->grp = ft_strnew(ft_strlen(grp->gr_name));
		elem->grp = ft_strcpy(elem->grp, grp->gr_name);
	}
	elem->date = ft_strnew(12);
	if (time(NULL) - stat.st_mtime > 2628000 * 6)
	{
		date = ft_strsub(ctime(&elem->stat.st_mtime), 4, 7);
		elem->date = ft_strcat(elem->date, date);
		ft_strdel(&date);
		date = ft_strsub(ctime(&elem->stat.st_mtime), 19, 5);
	}
	else
		if (!(date = ft_strsub(ctime(&elem->stat.st_mtime), 4, 12)))
			perror(NAME);
	elem->date = ft_strcat(elem->date, date);
	ft_strdel(&date);
	elem->major = major(stat.st_rdev);
	elem->minor = minor(stat.st_rdev);
}

t_elem	*ls_lstnew(char *name, char *path, struct stat stat, t_ls *ls)
{
	t_elem	*elem;

	if ((elem = (t_elem*)ft_memalloc(sizeof(t_elem))))
	{
		if ((elem->name = (name ? ft_strnew(ft_strlen(name)) : NULL)))
			elem->name = ft_strcpy(elem->name, name);
		if ((elem->path = (path ? ft_strnew(ft_strlen(path)) : NULL)))
			elem->path = ft_strcpy(elem->path, path);
		elem->stat = stat;
		elem->link = 0;
		elem->size = 0;
		elem->user = NULL;
		elem->grp = NULL;
		elem->date = NULL;
		if (ls->flags[2])
			long_flag(elem, stat);
		else
		{
			elem->user_len = 0;
			elem->grp_len = 0;
			elem->size_len = 0;
			elem->link_len = 0;
			elem->major = 0;
			elem->minor = 0;
		}
		elem->next = NULL;
	}
	return (elem);
}
