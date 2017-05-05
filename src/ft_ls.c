/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:23:40 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/05 17:35:58 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#include <sys/stat.h>
#include <time.h>
void	print(t_list *list)
{
	ft_putendl(list->content);
}

void	find_elem(char **argv, int size, t_ls ls)
{
	int			i;
	struct stat	s;
	t_list		*direc;
	t_list		*files;
	t_list		*nonex;
if (ls.flags[0])
	;
	i = -1;
	direc = NULL;
	files = NULL;
	nonex = NULL;
	while (++i < size)
	{
		s.st_ino = 0;
		lstat(argv[i], &s);
		if (!s.st_ino)
			nonex = ft_lstaddalpha(&nonex, ft_lstnew(argv[i], ft_strlen(argv[i])));
		else if (S_ISDIR(s.st_mode))
			direc = ft_lstaddalpha(&direc, ft_lstnew(argv[i], ft_strlen(argv[i])));
		else
			files = ft_lstaddalpha(&files, ft_lstnew(argv[i], ft_strlen(argv[i])));
	}
	ft_lstiter(nonex, &print);
	ft_putendl("");
	ft_lstiter(files, &print);
	ft_putendl("");
	ft_lstiter(direc, &print);
}

int	main(int argc, char **argv)
{
	int		i;
	t_ls	ls;

	i = 1;
	fill_tab(ls.flags, NB_FLAG, 0);
	if (argc > 1)
	{
		i += find_flags(&argv[i], ls.flags);
		find_elem(&argv[i], argc - i, ls);
	}
	/*else
		print_directory(".", NULL);*/
	return (0);
}
