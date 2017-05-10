/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:23:40 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/09 20:20:52 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print(t_list *list)
{
	ft_putendl(list->content);
}

#include <stdlib.h>
void	delete(void *list, size_t size)
{
	if (size)
		;
	if (list)
		free(list);
	list = NULL;
}

#include <unistd.h>
#include <sys/stat.h>
void	find_elem(char **argv, int size, t_ls *ls)
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
			nonex = ft_lstaddalpha(&nonex,
					ft_lstnew(argv[i], ft_strlen(argv[i])));
		else if (S_ISDIR(s.st_mode))
		{	
			direc = (ls->flags[4] ?
					ls_lstaddtime(&direc, ls_lstnew(argv[i], "", s)) :
					ls_lstaddalpha(&direc, ls_lstnew(argv[i], "", s)));
			ls->nb_dir += 1;
		}
		else
			files = (ls->flags[4] ?
					ls_lstaddtime(&files, ls_lstnew(argv[i], "", s)) :
					ls_lstaddalpha(&files, ls_lstnew(argv[i], "", s)));
	}
	ls_nonex(nonex, ls);
	ls_lstiter(files, &print_name);
	if (files && direc)
		ft_putendl("");
	ls_lstiter(direc, &print_name);
	ft_lstdel(&nonex, &delete);
	//ls_lstdel(&files);
	//ls_lstdel(&direc);
	//sleep(5);
}

int	main(int argc, char **argv)
{
	int		i;
	t_ls	ls;

	i = 1;
	ls.error = 0;
	ls.nb_dir = 0;
	fill_tab(ls.flags, NB_FLAG, 0);
	if (argc > 1)
	{
		i += find_flags(&argv[i], ls.flags);
		find_elem(&argv[i], argc - i, &ls);
	}
	/*else
		print_directory(".", NULL);*/
	return (ls.error);
}
