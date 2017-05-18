/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_directory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 09:16:59 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/18 16:50:46 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "ft_printf.h"
#include <sys/stat.h>
#include <dirent.h>

static char		*concat(const char *path, const char *name)
{
	int		size;
	char	*concat;

	concat = NULL;
	if (path && name)
	{
		size = ft_strlen(path) + 1 + ft_strlen(name);
		concat = ft_strnew(size);
		concat = ft_strcpy(concat, path);
		if (ft_strcmp(path, "/"))
			concat = ft_strcat(concat, "/");
		concat = ft_strcat(concat, name);
	}
	return (concat);
}

static t_elem	*read_dir(DIR *fold, char *name, t_ls *ls)
{
	struct dirent	*d;
	struct stat		s;
	t_elem			*elem;
	t_elem			*direc;
	char			*str;

	elem = NULL;
	direc = NULL;
	while ((d = readdir(fold)))
	{
		s.st_ino = 0;
		str = concat(name, d->d_name);
		lstat(str, &s);
		if (d->d_name[0] != '.' || (ls && ls->flags[1]))
		{
			if (!S_ISLNK(s.st_mode))
				elem = add_files(elem, d->d_name, ls, s);
			else
				elem = add_files_path(elem, str, ls, s);
		}
		if (d->d_name[0] != '.' && ls && ls->flags[0] && S_ISDIR(s.st_mode))
			direc = add_direc(direc, str, ls, s);
		ft_strdel(&str);
	}
	ls_files(&elem, ls);
	return (direc);
}

void			print_directory(t_elem *list, t_ls *ls)
{
	DIR				*fold;
	t_elem			*direc;

	if (ls && (ls->nb_files || ls->nb_direc > 1 || ls->nb_nonex))
		ft_printf("%s:\n", list->name);
	if ((fold = opendir(list->name)))
	{
		direc = read_dir(fold, list->name, ls);
		if (direc)
			ls_direc(&direc, ls);
		closedir(fold);
	}
	else
		put_error(list, ls);
}
