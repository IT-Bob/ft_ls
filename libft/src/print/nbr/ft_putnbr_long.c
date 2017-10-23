/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:40:44 by aguerin           #+#    #+#             */
/*   Updated: 2017/06/28 17:20:50 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche le nombre 'n' sur la sortie standard et retourne le nombre
** de caractères affichés.
*/

int	ft_putnbr_long(long long int n)
{
	unsigned long long int	m;
	int						cmp;

	cmp = 0;
	if (n < 0)
	{
		cmp += ft_putchar('-');
		m = -n;
	}
	else
		m = n;
	if (m > 9)
	{
		cmp += ft_putnbr_long(m / 10);
		cmp += ft_putchar((m % 10) + '0');
	}
	else
		cmp += ft_putchar(m + '0');
	return (cmp);
}
