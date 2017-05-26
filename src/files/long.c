/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 12:31:17 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/26 15:52:37 by aguerin          ###   ########.fr       */
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

static void	print_type(mode_t st_mode)
{
	if (S_ISFIFO(st_mode))
		ft_putchar('p');
	else if (S_ISCHR(st_mode))
		ft_putchar('c');
	else if (S_ISDIR(st_mode))
		ft_putchar('d');
	else if (S_ISDIR(st_mode))
		ft_putchar('d');
	else if (S_ISBLK(st_mode))
		ft_putchar('b');
	else if (S_ISLNK(st_mode))
		ft_putchar('l');
	else if (S_ISSOCK(st_mode))
		ft_putchar('s');
	else
		ft_putchar('-');
}

static void	print_permissions(mode_t st_mode)
{
	ft_putchar(((st_mode & S_IRUSR) ? 'r' : '-'));
	ft_putchar(((st_mode & S_IWUSR) ? 'w' : '-'));
	if (!(st_mode & S_IXUSR) && (st_mode & S_ISUID))
		ft_putchar('S');
	else if ((st_mode & S_IXUSR) && (st_mode & S_ISUID))
		ft_putchar('s');
	else
		ft_putchar(((st_mode & S_IXUSR) ? 'x' : '-'));
	ft_putchar(((st_mode & S_IRGRP) ? 'r' : '-'));
	ft_putchar(((st_mode & S_IWGRP) ? 'w' : '-'));
	if (!(st_mode & S_IXGRP) && (st_mode & S_ISGID))
		ft_putchar('S');
	else if ((st_mode & S_IXGRP) && (st_mode & S_ISGID))
		ft_putchar('s');
	else
		ft_putchar(((st_mode & S_IXGRP) ? 'x' : '-'));
	ft_putchar(((st_mode & S_IROTH) ? 'r' : '-'));
	ft_putchar(((st_mode & S_IWOTH) ? 'w' : '-'));
	if (!(st_mode & S_IXOTH) && (st_mode & S_ISVTX))
		ft_putchar('T');
	else if ((st_mode & S_IXOTH) && (st_mode & S_ISVTX))
		ft_putchar('t');
	else
		ft_putchar(((st_mode & S_IXOTH) ? 'x' : '-'));
	ft_putstr("  ");
}

static void	print_other(t_elem *elem, t_ls *ls)
{
	ft_putxchar(' ', ls->link_mlen - elem->link_len);
	ft_putnbrs(elem->link);
	ft_putstrs(elem->user);
	ft_putxchar(' ', ls->user_mlen - elem->user_len + 1);
	ft_putstrs(elem->grp);
	ft_putxchar(' ', ls->grp_mlen - elem->grp_len + 1);
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
		ft_putxchar(' ', ls->size_mlen + ls->dec - elem->size_len);
		ft_putnbrs(elem->size);
	}
	ft_putstrs(elem->date);
	ft_putstr(elem->name);
}

static void	print_link(t_elem *elem)
{
	char	*link;
	int		size;

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

void		print_all(t_elem *elem, t_ls *ls)
{
	if (!elem || !ls)
		exit(-1);
	print_type(elem->stat.st_mode);
	print_permissions(elem->stat.st_mode);
	print_other(elem, ls);
	print_link(elem);
}
