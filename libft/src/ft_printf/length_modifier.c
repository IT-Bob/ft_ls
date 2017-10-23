/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:32:00 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/22 16:32:23 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <inttypes.h>

/*
** 1 -> hh, 2 -> h, 3 -> l, 4 -> ll, 5 -> j, 6 -> z
*/

int				find_length_modifier(const char *format)
{
	int	i;

	i = 0;
	if (format[i] == 'h')
	{
		if (format[i + 1] == 'h')
			return (1);
		return (2);
	}
	if (format[i] == 'l')
	{
		if (format[i + 1] == 'l')
			return (4);
		return (3);
	}
	if (format[i] == 'j')
		return (5);
	if (format[i] == 'z')
		return (6);
	return (0);
}

long long		length_modifier_di(int modifier, va_list va)
{
	if (modifier == 1)
		return ((char)va_arg(va, int));
	if (modifier == 2)
		return ((short)va_arg(va, int));
	if (modifier == 3)
		return (va_arg(va, long));
	if (modifier == 4)
		return (va_arg(va, long long));
	if (modifier == 5)
		return (va_arg(va, intmax_t));
	if (modifier == 6)
		return (va_arg(va, size_t));
	return (va_arg(va, int));
}

unsigned long	length_modifier_oux(int modifier, va_list va)
{
	if (modifier == 1)
		return ((unsigned char)va_arg(va, unsigned int));
	if (modifier == 2)
		return ((unsigned short)va_arg(va, unsigned int));
	if (modifier == 3)
		return (va_arg(va, unsigned long));
	if (modifier == 4)
		return (va_arg(va, unsigned long long));
	if (modifier == 5)
		return (va_arg(va, uintmax_t));
	if (modifier == 6)
		return (va_arg(va, size_t));
	return (va_arg(va, unsigned int));
}

long long		length_modifier_dou_cap(int modifier, va_list va)
{
	if (modifier == 3)
		return (va_arg(va, long));
	if (modifier == 4)
		return (va_arg(va, long long));
	if (modifier == 5)
		return (va_arg(va, intmax_t));
	if (modifier == 6)
		return (va_arg(va, size_t));
	return (va_arg(va, long int));
}
