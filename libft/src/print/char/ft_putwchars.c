/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:11:50 by aguerin           #+#    #+#             */
/*   Updated: 2017/06/28 17:06:23 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putwcharl permet d'afficher les caractères étendus, suivi d'un espace.
*/

int	ft_putwchars(long c)
{
	return (ft_putwchar(c) + ft_putchar(' '));
}
