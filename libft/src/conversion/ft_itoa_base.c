/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 10:27:16 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/02 10:54:17 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** ft_itoa_base() peut convertir un nombre positif de la base 10 vers n'importe
** quelle base comprise entre 1 et 38.
*/

static char	*ft_zero(char *nbr)
{
	nbr = (char*)ft_memalloc(sizeof(char) * 2);
	ft_strcpy(nbr, "0");
	return (nbr);
}

static int	ft_size_itoa(unsigned long nb, int base)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		i++;
		nb /= base;
	}
	return (i);
}

char		*ft_itoa_base(unsigned long nb, int base)
{
	long	mod;
	size_t	size;
	char	*nbr;

	if (base < 2 || base > 37)
	{
		ft_putendl("Base incorrect...");
		return (NULL);
	}
	nbr = NULL;
	if (nb == 0)
		return (ft_zero(nbr));
	size = ft_size_itoa(nb, base);
	if ((nbr = (char*)ft_memalloc(size + 1)))
	{
		nbr[size--] = '\0';
		while (nb > 0)
		{
			mod = nb % base;
			nbr[size--] = (mod > 9 ? mod - 10 + 'a' : mod + '0');
			nb /= base;
		}
		return (nbr);
	}
	return (NULL);
}
