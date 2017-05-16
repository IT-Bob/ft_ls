/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:53:30 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/16 16:37:59 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

#include <grp.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <stdlib.h>
#include <time.h>

static void permissions(mode_t st_mode)
{
	int	perm[11];
	int i;

	i = 0;
	if (S_ISFIFO(st_mode))
		perm[0] = 'p';
	else if (S_ISCHR(st_mode))
		perm[0] = 'c';
	else if (S_ISDIR(st_mode))
		perm[0] = 'd';
	else if (S_ISDIR(st_mode))
		perm[0] = 'd';
	else if (S_ISBLK(st_mode))
		perm[0] = 'b';
	else if (S_ISLNK(st_mode))
		perm[0] = 'l';
	else
		perm[0] = '-';
	perm[1] = (st_mode & S_IRUSR) ? 'r' : '-';
	perm[2] = (st_mode & S_IWUSR) ? 'w' : '-';
	perm[3] = (st_mode & S_IXUSR) ? 'x' : '-';
	perm[4] = (st_mode & S_IRGRP) ? 'r' : '-';
	perm[5] = (st_mode & S_IWGRP) ? 'w' : '-';
	perm[6] = (st_mode & S_IXGRP) ? 'x' : '-';
	perm[7] = (st_mode & S_IROTH) ? 'r' : '-';
	perm[8] = (st_mode & S_IWOTH) ? 'w' : '-';
	if (!(st_mode & S_IXOTH) && (st_mode & S_ISVTX))
		perm[9] = 'T';
	else if ((st_mode & S_IXOTH) && (st_mode & S_ISVTX))
		perm[9] = 't';
	else
		perm[9] = (st_mode & S_IXOTH) ? 'x' : '-';
	while (i < 11)
		ft_putchar(perm[i++]);
	ft_putstr("  ");
}
static void	print_all(t_elem *elem)
{
	struct passwd	*pwd;
	struct group	*grp;
	char			*date;

	pwd = NULL;
	if (elem)
	{
		permissions(elem->stat.st_mode);
		pwd = getpwuid(elem->stat.st_uid);
		ft_putnbrs(elem->stat.st_nlink);
		grp = getgrgid(elem->stat.st_gid);
		ft_putstrs(pwd->pw_name);
		ft_putstrs(grp->gr_name);
		ft_putnbrs(elem->stat.st_size);
		if ((date = ft_strsub(ctime(&elem->stat.st_mtime), 4, 12)))
		{
			ft_putstrs(date);
			ft_strdel(&date);
		}
		ft_putendl(elem->name);
	}
}

void	ls_files(t_elem **files, t_ls *ls)
{
	if (*files)
	{
		if (ls && ls->flags[3])
		{
			if (ls->flags[2])
				ls_lstiter_reverse(*files, &print_all);
			else
				ls_lstiter_reverse(*files, &print_name);
		}
		else
		{
			if (ls && ls->flags[2])
				ls_lstiter(*files, &print_all);
			else
				ls_lstiter(*files, &print_name);
		}
		ls_lstdel(files);
	}
}
