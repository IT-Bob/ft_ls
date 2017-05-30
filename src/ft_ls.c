/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:23:40 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/30 12:22:35 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

/*
** find_elem() trouve les éléments envoyés dans les paramètres de argv (censés
** indiquer des fichiers et dossiers).
*/

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
		if (S_ISLNK(s.st_mode) && ls && !ls->flags[2])
			stat(argv[i], &s);
		if (!s.st_ino)
			nonex = add_nonex(nonex, argv[i], ls);
		else if (S_ISDIR(s.st_mode))
			direc = add_direc(direc, argv[i], ls, s);
		else
		{
			if (!S_ISLNK(s.st_mode))
				files = add_files(files, argv[i], ls, s);
			else
				files = add_name_path(files, argv[i], ls, s);
		}
	}
	ls->total = -1;
	ls_nonex(&nonex);
	ls_files(&files, ls);
	ls_direc(&direc, ls);
}

void		initialise_size(t_ls *ls)
{
	if (!ls)
		ft_perror("Paramètre NULL - initialise_size()", -1);
	ls->link_mlen = 0;
	ls->user_mlen = 0;
	ls->grp_mlen = 0;
	ls->size_mlen = 0;
	ls->majo_mlen = 0;
	ls->mino_mlen = 0;
	ls->total = -1;
	ls->dec = 0;
}

static void	initialise(t_ls *ls)
{
	if (!ls)
		ft_perror("Paramètre NULL - initialise()", -1);
	fill_tab(ls->flags, NB_FLAG, 0);
	ls->error = 0;
	ls->nb_direc = 0;
	ls->nb_files = 0;
	ls->nb_nonex = 0;
	initialise_size(ls);
}

int			main(int argc, char **argv)
{
	int		i;
	t_ls	ls;

	i = 1;
	initialise(&ls);
	i += find_flags(&argv[i], ls.flags);
	if (i == argc || argc == 1)
	{
		argv[0] = ".";
		i = 0;
		argc = 1;
	}
	find_elem(&argv[i], argc - i, &ls);
	return (ls.error);
}
