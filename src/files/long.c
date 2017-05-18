/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 12:31:17 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/18 16:59:17 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <grp.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <stdlib.h>
#include <time.h>
#include "ft_printf.h"
#include <unistd.h>
#include <time.h>
#include <limits.h>

static void permissions(mode_t st_mode)
{
	int	perm[10];
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
	else if (S_ISSOCK(st_mode))
		perm[0] = 's';
	else
		perm[0] = '-';
	perm[1] = (st_mode & S_IRUSR) ? 'r' : '-';
	perm[2] = (st_mode & S_IWUSR) ? 'w' : '-';
	if (!(st_mode & S_IXUSR) && (st_mode & S_ISUID))
		perm[3] = 'S';
	else if ((st_mode & S_IXUSR) && (st_mode & S_ISUID))
		perm[3] = 's';
	else
		perm[3] = (st_mode & S_IXUSR) ? 'x' : '-';
	perm[4] = (st_mode & S_IRGRP) ? 'r' : '-';
	perm[5] = (st_mode & S_IWGRP) ? 'w' : '-';
	if (!(st_mode & S_IXGRP) && (st_mode & S_ISGID))
		perm[6] = 'S';
	else if ((st_mode & S_IXGRP) && (st_mode & S_ISGID))
		perm[6] = 's';
	else
		perm[6] = (st_mode & S_IXGRP) ? 'x' : '-';
	perm[7] = (st_mode & S_IROTH) ? 'r' : '-';
	perm[8] = (st_mode & S_IWOTH) ? 'w' : '-';
	if (!(st_mode & S_IXOTH) && (st_mode & S_ISVTX))
		perm[9] = 'T';
	else if ((st_mode & S_IXOTH) && (st_mode & S_ISVTX))
		perm[9] = 't';
	else
		perm[9] = (st_mode & S_IXOTH) ? 'x' : '-';
	while (i < 10)
		ft_putchar(perm[i++]);
	ft_putstr("  ");
}

static void	print_all(t_elem *elem)
{
	struct passwd	*pwd;
	struct group	*grp;
	char	*link;
	int		size;
	char	*date;

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
		if (time(NULL) - elem->stat.st_mtime > 2628000 * 6)
		{
			ft_putstrs((date = ft_strsub(ctime(&elem->stat.st_mtime), 4, 6)));
			ft_strdel(&date);
			ft_putstrs((date = ft_strsub(ctime(&elem->stat.st_mtime), 20, 4)));
			ft_strdel(&date);
		}
		else
			if ((date = ft_strsub(ctime(&elem->stat.st_mtime), 4, 12)))
			{
				ft_putstrs(date);
				ft_strdel(&date);
			}
		ft_putstrs(elem->name);
		if (S_ISLNK(elem->stat.st_mode))
		{
			size = PATH_MAX;
			link = ft_strnew(size);
			if ((readlink(elem->path, link, size - 1) >= 0))
				ft_printf("-> %s\n", link);
			else
				perror(elem->path);
			ft_strdel(&link);
		}
		else
			ft_putchar('\n');
	}
}

void	print_standard_long(t_elem *elem)
{
	while (elem)
	{
		print_all(elem);
		elem = elem->next;
	}
}

void	print_reverse_long(t_elem *elem)
{
	if (elem)
	{
		print_reverse_long(elem->next);
		print_all(elem);
	}
}
