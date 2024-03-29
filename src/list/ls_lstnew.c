/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:23:40 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/30 12:11:18 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <sys/types.h>

static void	date(t_elem *elem, struct stat stat)
{
	char	*date;
	char	*times;

	date = NULL;
	elem->date = ft_strnew(12);
	times = ctime(&elem->stat.st_mtime);
	if (time(NULL) - stat.st_mtime > 2628000 * 6 || time(NULL) < stat.st_mtime)
	{
		if (!(date = ft_strsub(times, 4, 7)))
			ft_perror("Erreur - date()", -1);
		elem->date = ft_strcat(elem->date, date);
		elem->date = ft_strcat(elem->date, " ");
		ft_strdel(&date);
		if (!(date = ft_itoa(ft_atoi(&times[19]))))
			ft_perror("Erreur - date()", -1);
	}
	else if (!(date = ft_strsub(times, 4, 12)))
		perror(NAME);
	elem->date = ft_strcat(elem->date, date);
	ft_strdel(&date);
}

static void	long_flag(t_elem *elem, struct stat stat, t_ls *ls)
{
	struct passwd	*pwd;
	struct group	*grp;

	elem->link = stat.st_nlink;
	elem->size = stat.st_size;
	pwd = getpwuid(stat.st_uid);
	grp = getgrgid(stat.st_gid);
	if (!pwd || !grp)
	{
		perror(NAME);
		exit(-1);
	}
	elem->user = ft_strnew(ft_strlen(pwd->pw_name));
	elem->user = ft_strcpy(elem->user, pwd->pw_name);
	elem->grp = ft_strnew(ft_strlen(grp->gr_name));
	elem->grp = ft_strcpy(elem->grp, grp->gr_name);
	date(elem, stat);
	if (S_ISCHR(elem->stat.st_mode) || S_ISBLK(elem->stat.st_mode))
	{
		elem->major = major(stat.st_rdev);
		elem->minor = minor(stat.st_rdev);
		ls->dec = 1;
	}
}

static void	init(t_elem *elem)
{
	elem->user_len = 0;
	elem->grp_len = 0;
	elem->size_len = 0;
	elem->link_len = 0;
	elem->major = 0;
	elem->minor = 0;
	elem->link = 0;
	elem->size = 0;
	elem->user = NULL;
	elem->grp = NULL;
	elem->date = NULL;
}

t_elem		*ls_lstnew(char *name, char *path, struct stat stat, t_ls *ls)
{
	t_elem	*elem;

	if ((elem = (t_elem*)ft_memalloc(sizeof(t_elem))) && ls)
	{
		if ((elem->name = (name ? ft_strnew(ft_strlen(name)) : NULL)))
			elem->name = ft_strcpy(elem->name, name);
		if ((elem->path = (path ? ft_strnew(ft_strlen(path)) : NULL)))
			elem->path = ft_strcpy(elem->path, path);
		elem->stat = stat;
		init(elem);
		if (ls->flags[2])
			long_flag(elem, stat, ls);
		elem->next = NULL;
	}
	else
		ft_perror("Erreur - ls_lstnew()", -1);
	return (elem);
}
