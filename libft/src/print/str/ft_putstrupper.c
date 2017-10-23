/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 10:22:59 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/16 10:23:00 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstrupper(const char *str)
{
	int	i;
	int	cmp;

	if (!str)
		return (-1);
	i = 0;
	cmp = 0;
	while (str[i])
		cmp += ft_putchar(ft_toupper(str[i++]));
	return (cmp);
}
