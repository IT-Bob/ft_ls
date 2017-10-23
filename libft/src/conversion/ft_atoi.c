/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:31:36 by aguerin           #+#    #+#             */
/*   Updated: 2016/11/07 17:50:55 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_atoi() prend en entrée une chaîne de caractères (censée représenter un
** nombre) et renvoie sa représentation en int.
*/

int	ft_atoi(const char *str)
{
	int i;
	int nb;
	int neg;

	nb = 0;
	i = 0;
	neg = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) && str[i] <= 57 && str[i] != '\0')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (neg * nb);
}
