/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:28:48 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/15 16:29:04 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
** conversion pour %u ou %U
*/

int			conversion_u(const char *format, va_list va, int *cmp, char c)
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
	correction_specifier(specifier, 1, 0, 0);
	if (c == 'u')
		nb = length_modifier_oux(i, va);
	else
		nb = length_modifier_dou_cap(i, va);
	if (!nb && size[1] == -1)
		str = NULL;
	else if (!(str = ft_itoa_base(nb, 10)))
		return (-1);
	*cmp += print_r(str, size[0], size[1], specifier);
	ft_strdel(&str);
	return (1);
}
