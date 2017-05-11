/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:23:40 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/11 15:07:02 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>
#include <sys/stat.h>

static void	find_elem(char **argv, int size, t_ls *ls)
{
	int			i;
	struct stat	s;
	t_elem		*direc;
	t_elem		*files;
	t_list		*nonex;

	i = -1;
	direc = NULL;
	files = NULL;
	nonex = NULL;
	while (++i < size)
	{
		s.st_ino = 0;
		lstat(argv[i], &s);
		if (!s.st_ino)
			nonex = add_nonex(nonex, argv[i], ls);
		else if (S_ISDIR(s.st_mode))
			direc = add_direc(direc, argv[i], ls, s);
		else
			files = add_files(files, argv[i], ls, s);
	}
	ls_nonex(&nonex);
	ls_files(&files, ls);
	ls_direc(&direc, ls);
}

static void	initialise(t_ls *ls)
{
	ls->error = 0;
	ls->nb_direc = 0;
	ls->nb_files = 0;
	fill_tab(ls->flags, NB_FLAG, 0);
}

int			main(int argc, char **argv)
{
	int		i;
	t_ls	ls;

	i = 1;
	initialise(&ls);
	if (argc > 1)
	{
		i += find_flags(&argv[i], ls.flags);
		find_elem(&argv[i], argc - i, &ls);
	}
	if (argc == 1 || i == argc)
		print_directory(".", &ls);
	return (ls.error);
}
