/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:04:34 by aguerin           #+#    #+#             */
/*   Updated: 2017/06/06 17:45:19 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	print(const char *out, int width, int precision, int left)
{
	int	length;
	int	cmp;

	length = (out ? ft_strlen(out) : 0);
	cmp = 0;
	if (precision > 0 && precision < length)
		length = precision;
	else if (precision == -1)
		length = 0;
	if (!left)
		cmp += ft_putxchar(' ', width - length);
	if (out)
		cmp += ft_putnstr(out, length);
	if (left)
		cmp += ft_putxchar(' ', width - length);
	return (cmp);
}

int			conversion_s(const char *format, va_list va, int *cmp)
{
	char	*str;
	int		specifier[6];
	int		width;
	int		precision;

	precision = 0;
	width = 0;
	find(format, specifier, &width, &precision);
	correction_specifier(specifier, 0, 0, 0);
	if ((find_length_modifier(&format[1]) == 3))
		return (conversion_s_cap(format, va, cmp));
	if (!(str = va_arg(va, char*)))
		str = "(null)";
	if (precision)
		if (!(str = ft_strsub(str, 0, (precision == -1 ? 0 : precision))))
			return (-1);
	correction_specifier(specifier, 0, 0, 0);
	*cmp += print(str, width, precision, specifier[3]);
	if (precision)
		ft_strdel(&str);
	return (1);
}
