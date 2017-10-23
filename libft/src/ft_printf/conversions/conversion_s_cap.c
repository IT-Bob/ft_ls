/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s_cap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:43:35 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/15 15:43:51 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	print(wchar_t *out, int width, int precision, int left)
{
	int	length;
	int	cmp;

	length = (!precision ? ft_strwbytlen(out) : 0);
	cmp = 0;
	if (!left)
		cmp += ft_putxchar(' ', width - length);
	if (!precision)
		cmp += ft_putwstr(out);
	if (left)
		cmp += ft_putxchar(' ', width - length);
	return (cmp);
}

int			conversion_s_cap(const char *format, va_list va, int *cmp)
{
	wchar_t	*str;
	int		specifier[6];
	int		width;
	int		precision;

	width = 0;
	precision = 0;
	find(format, specifier, &width, &precision);
	correction_specifier(specifier, 0, 0, 0);
	if (!(str = va_arg(va, wchar_t*)))
		str = L"(null)";
	*cmp += print(str, width, precision, specifier[3]);
	return (1);
}
