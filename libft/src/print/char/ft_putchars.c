/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:15:17 by aguerin           #+#    #+#             */
/*   Updated: 2017/06/28 17:04:52 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche un caractère suivi d'un espace.
*/

int	ft_putchars(char c)
{
	return (ft_putchar(c) + ft_putchar(' '));
}
