/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:58:53 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/15 15:59:11 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	print_l(const char *out, int width, int precision, int specifier[])
{
	int	cmp;

	cmp = 0;
	if (specifier[2] && !specifier[5])
		cmp += ft_putchar(' ');
	if (specifier[4] || specifier[5])
		cmp += ft_putchar((specifier[5] ? '-' : '+'));
	cmp += ft_putxchar('0', precision);
	cmp += ft_putstr(out);
	cmp += ft_putxchar(' ', width);
	return (cmp);
}

static int	print(const char *out, int width, int precision, int specifier[])
{
	int	cmp;

	if (adjust(&width, &precision, out, specifier))
		out++;
	if (specifier[3])
		return (print_l(out, width, precision, specifier));
	cmp = 0;
	if (!specifier[1])
		cmp += ft_putxchar(' ', width);
	if (specifier[2] && !specifier[5])
		cmp += ft_putchar(' ');
	if (specifier[4] || specifier[5])
		cmp += ft_putchar((specifier[5] ? '-' : '+'));
	if (specifier[1])
		cmp += ft_putxchar('0', width);
	cmp += ft_putxchar('0', precision);
	if (out)
		cmp += ft_putstr(out);
	return (cmp);
}

/*
** conversion pour %d ou %D
*/

int			conversion_d(const char *format, va_list va, int *cmp, char c)
{
	char		*str;
	int			specifier[6];
	int			width;
	int			precision;
	long int	i;

	width = 0;
	precision = 0;
	i = find(format, specifier, &width, &precision);
	i = find_length_modifier(&format[i]);
	if (c == 'D')
		i = length_modifier_dou_cap(i, va);
	else
		i = length_modifier_di(i, va);
	if (!i && precision == -1)
		str = NULL;
	else if (!(str = ft_itoa_long(i)))
		return (-1);
	correction_specifier(specifier, 1, 0, 1);
	specifier[5] = ((str && str[0] == '-' ? 1 : 0));
	*cmp += print(str, width, precision, specifier);
	ft_strdel(&str);
	return (1);
}
