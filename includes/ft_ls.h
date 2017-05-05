/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 11:05:47 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/05 17:24:16 by aguerin          ###   ########.fr       */
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

# define NAME		"ft_ls"
# define FLAGS_NAME	"Ralrt1"
# define FLAGS		"Ralrt1"
# define NB_FLAG	6

typedef struct	s_ls
{
	int	tab[NB_FLAG];
}				t_ls;

/*
** src/flags
*/

int				find_flags(char **argv, t_ls ls);
void			illegal_option(char c);

#endif
