/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 12:31:17 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/22 21:12:51 by aguerin          ###   ########.fr       */
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

static void	print_all(t_elem *elem, t_ls *ls)
{
	char	*link;
	int		size;

	if (elem)
	{
		permissions(elem->stat.st_mode);
		ft_putxchar(' ', ls->link_mlen - elem->link_len);
		ft_putnbrs(elem->link);
		ft_putstrs(elem->user);
		ft_putxchar(' ', ls->user_mlen - elem->user_len);
		ft_putchar(' ');
		ft_putstrs(elem->grp);
		ft_putxchar(' ', ls->grp_mlen - elem->grp_len);
		ft_putchar(' ');
		if (S_ISCHR(elem->stat.st_mode) || S_ISBLK(elem->stat.st_mode))
		{
			ft_putxchar(' ', ls->majo_mlen - elem->majo_len + 1);
			ft_putnbr(elem->major);
			ft_putstrs(",");
			ft_putxchar(' ', ls->mino_mlen - elem->mino_len);
			ft_putnbrs(elem->minor);
		}
		else
		{
			ft_putxchar(' ', ls->size_mlen - elem->size_len);
			ft_putnbrs(elem->size);
		}
		ft_putstrs(elem->date);
		ft_putstr(elem->name);
		if (S_ISLNK(elem->stat.st_mode))
		{
			ft_putchar(' ');
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

void	print_standard_long(t_elem *elem, t_ls *ls)
{
	while (elem)
	{
		print_all(elem, ls);
		elem = elem->next;
	}
}

void	print_reverse_long(t_elem *elem, t_ls *ls)
{
	if (elem)
	{
		print_reverse_long(elem->next, ls);
		print_all(elem, ls);
	}
}
