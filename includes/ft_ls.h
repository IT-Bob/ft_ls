/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 11:05:47 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/11 16:27:23 by aguerin          ###   ########.fr       */
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
	int	error;
	int	nb_direc;
	int	nb_files;
	int	nb_nonex;
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
void			ls_lstdel(t_elem **elem);
void			ls_lstiter(t_elem *lst, void(*f)(t_elem*));
void			ls_lstiter_reverse(t_elem *list, void (*f)(t_elem*));
t_elem			*ls_lstnew(char *name, struct stat stat);
void			print_name(t_elem *elem);
void			print_path(t_elem *path);

/*
** src/direc
*/

t_elem			*add_direc(t_elem *direc, char *name, t_ls *ls, struct stat s);
void			ls_direc(t_elem **direc, t_ls *ls);

/*
** src/files
*/

t_elem			*add_files(t_elem *files, char *name, t_ls *ls, struct stat s);
void			ls_files(t_elem **files, t_ls *ls);

/*
** src/nonex
*/

t_list			*add_nonex(t_list *nonex, char *name, t_ls *ls);
void			del(void *content, size_t size);
void			ls_nonex(t_list **nonex);
void			print_nonex(t_list *list);

/*
** src/print
*/

void			print_directory(char *path, t_ls *ls);

#endif
