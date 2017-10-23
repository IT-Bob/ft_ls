/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:27:52 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/15 16:28:10 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	print(const char *out, int width, int left)
{
	int	length;
	int	cmp;

	length = ft_strlen(out) + 2;
	cmp = 0;
	if (!left)
		cmp += ft_putxchar(' ', width - length);
	cmp += ft_putstr("0x");
	cmp += ft_putstr(out);
	if (left)
		cmp += ft_putxchar(' ', width - length);
	return (cmp);
}

int			conversion_p(const char *format, va_list va, int *cmp)
{
	char	*str;
	int		specifier[6];
	int		width;

	width = 0;
	find(format, specifier, &width, NULL);
	correction_specifier(specifier, 0, 0, 0);
	if (!(str = ft_itoa_base(va_arg(va, unsigned long), 16)))
		return (-1);
	*cmp += print(str, width, specifier[3]);
	ft_strdel(&str);
	return (1);
}
