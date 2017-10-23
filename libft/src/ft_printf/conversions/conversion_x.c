/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:30:03 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/15 16:30:34 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
** conversion pour %x ou %X
*/

int			conversion_x(const char *format, va_list va, int *cmp, char c)
{
	char			*str;
	int				specifier[6];
	int				size[2];
	unsigned long	nb;
	int				i;

	size[0] = 0;
	size[1] = 0;
	i = find(format, specifier, &size[0], &size[1]);
	i = find_length_modifier(&format[i]);
	correction_specifier(specifier, 1, 1, 0);
	if (!(nb = length_modifier_oux(i, va)))
		specifier[0] = 0;
	if (!nb && size[1] == -1)
		str = NULL;
	else if (!(str = ft_itoa_base(nb, 16)))
		return (-1);
	if (c == 'X' && str)
		ft_strtoupper(str);
	if (specifier[0])
		specifier[0] = (specifier[0] && c == 'X' ? 3 : 2);
	*cmp += print_r(str, size[0], size[1], specifier);
	ft_strdel(&str);
	return (1);
}
