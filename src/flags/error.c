/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:11:28 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/22 13:36:47 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_printf.h"
#include <stdlib.h>

/*
** illegal_option() est appelée lorsqu'un flag incorrect est renseigné.
** Elle affiche sur la sortie d'erreur un message et l'usage de ft_ls
** puis quitte le programme avec la valeur -1.
*/

void	illegal_option(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ", 2);
	ft_putstr_fd(NAME, 2);
	ft_putstr_fd(" [-", 2);
	ft_putstr_fd(FLAGS_LIST, 2);
	ft_putstr_fd("] [file ...]\n", 2);
	exit(-1);
}
