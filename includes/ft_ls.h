/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 11:05:47 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/09 17:11:06 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** FLAGS contient les flags autorisés par ft_ls.
** NB_FLAG correspond au nombre de flags autorisés.
** Les cases de flags[] égales à 1 correspondent aux flags envoyés à ft_ls.
** c-à-d : flags[2] == 1 signifie que le flag FLAGS[2] est indiqué, donc '-l'.
** length_f et length_f stocke la longueur de la chaîne la plus longue contenue
** respectivement dans les listes files et direc.
*/

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <sys/stat.h>

# define NAME		"ft_ls"
# define FLAGS_NAME	"Ralrt1"
# define FLAGS		"Ralrt1"
# define NB_FLAG	6

typedef struct	s_ls
{
	int	flags[NB_FLAG];
}				t_ls;

typedef struct	s_elem
{
	char			*name;
	char			*path;
	struct stat		stat;
	struct s_elem	*next;
}				t_elem;

/*
** src/flags
*/

int				find_flags(char **argv, int flags[]);
void			illegal_option(char c);

/*
** src/list
*/

t_elem			*ls_lstaddalpha(t_elem **alst, t_elem *new);
t_elem			*ls_lstaddtime(t_elem **alst, t_elem *new);
void			ls_lstiter(t_elem *lst, void(*f)(t_elem *elem));
t_elem			*ls_lstnew(char *name, char *path, struct stat stat);
void			print_name(t_elem *elem);
void			print_path(t_elem *path);

#endif
