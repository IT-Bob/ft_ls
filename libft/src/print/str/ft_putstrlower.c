/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrlower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 10:22:49 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/16 10:22:52 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstrlower(const char *str)
{
	int	i;
	int	cmp;

	if (!str)
		return (-1);
	i = 0;
	cmp = 0;
	while (str[i])
		cmp += ft_putchar(ft_tolower(str[i++]));
	return (cmp);
}
