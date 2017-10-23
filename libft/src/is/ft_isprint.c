/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:47:26 by aguerin           #+#    #+#             */
/*   Updated: 2016/11/07 12:56:52 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isprint() renvoie 1
** si le caractère donné en paramètre est un caractère affichable.
*/

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 39) ||
		(c >= 40 && c <= 47) ||
		(c >= 58 && c <= 64) ||
		(c >= 91 && c <= 96) ||
		(c >= 123 && c <= 126) ||
		(ft_isalnum(c)))
		return (1);
	return (0);
}
