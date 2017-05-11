/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_directory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 09:16:59 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/11 16:54:08 by aguerin          ###   ########.fr       */
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
		concat = ft_strcat(concat, "/");
		concat = ft_strcat(concat, name);
	}
	return (concat);
}

static t_elem	*read_dir(DIR *fold, char *path, t_ls *ls)
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
		str = concat(path, d->d_name);
		lstat(str, &s);
		if (d->d_name[0] != '.' || (ls && ls->flags[1]))
			elem = add_files(elem, d->d_name, ls, s);
		if (d->d_name[0] != '.' && ls && ls->flags[0] && S_ISDIR(s.st_mode))
			direc = add_direc(direc, str, ls, s);
		ft_strdel(&str);
	}
	ls_files(&elem, ls);
	return (direc);
}

void			print_directory(char *path, t_ls *ls)
{
	DIR				*fold;
	t_elem			*direc;

	if (ls && ((ls->nb_direc > 1) || ls->nb_nonex))
		ft_printf("%s:\n", path);
	if ((fold = opendir(path)))
	{
		direc = read_dir(fold, path, ls);
		if (direc)
			ls_direc(&direc, ls);
		closedir(fold);
	}
	else
		put_error(path, ls);
}
