/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:11:28 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/05 17:41:24 by aguerin          ###   ########.fr       */
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
	ft_printf("%s: illegal option -- %c\nusage: ls [-%s] [file ...]\n",
				NAME, c, FLAGS_NAME);
	exit(-1);
}
