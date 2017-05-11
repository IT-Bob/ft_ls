/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_directory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 09:16:59 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/11 10:46:25 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "ft_printf.h"
#include <sys/stat.h>
#include <dirent.h>

void	print_directory(char *path, t_ls *ls)
{
	if (path || ls)
		;
	/*DIR				*fold;
	struct dirent	*content;
	struct stat		stat;
	t_elem			*elem;
	t_elem			*direc;

	char *str = ft_strjoin(path, "/");
	if ((fold = opendir(path)))
	{
		if (ls && (ls->nb_direc > 1 || ls->flags[0]))
			ft_printf("%s:\n", path);
		elem = NULL;
		direc = NULL;
		while((content = readdir(fold)))
		{
			stat.st_ino = 0;
			lstat(ft_strjoin(str, content->d_name), &stat);
			if (content->d_name[0] != '.' || (ls && ls->flags[1]))
				elem = add_files(elem, content->d_name, ls, stat);
			if (content->d_name[0] != '.' && ls && ls->flags[0] && S_ISDIR(stat.st_mode))
				direc = add_direc(direc, ft_strjoin(str, content->d_name), ls, stat);
		}
		ls_files(&elem, ls);
		if (direc)
			ls_direc(&direc, ls);
		closedir(fold);
	}*/
}
