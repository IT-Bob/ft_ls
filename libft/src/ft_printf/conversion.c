/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:39:55 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/15 14:40:10 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	conversion(const char *format, va_list va, int i, int *cmp)
{
	if (format[i] == 's')
		return (conversion_s(format, va, cmp));
	else if (format[i] == 'S')
		return (conversion_s_cap(format, va, cmp));
	else if (format[i] == 'p')
		return (conversion_p(format, va, cmp));
	else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'D')
		return (conversion_d(format, va, cmp, format[i]));
	else if (format[i] == 'o' || format[i] == 'O')
		return (conversion_o(format, va, cmp, format[i]));
	else if (format[i] == 'u' || format[i] == 'U')
		return (conversion_u(format, va, cmp, format[i]));
	else if (format[i] == 'x' || format[i] == 'X')
		return (conversion_x(format, va, cmp, format[i]));
	else if (format[i] == 'c')
		return (conversion_c(format, va, cmp));
	else if (format[i] == 'C')
		return (conversion_c_cap(format, va, cmp));
	else if (format[i] == '%')
		return (conversion_percent(format, cmp));
	return (0);
}

int			find_conversion(const char *format, va_list va, int *cmp)
{
	int	i;
	int ret;

	i = 1;
	ret = conversion(format, va, i, cmp);
	while (format[i] && !ret)
	{
		i++;
		ret = conversion(format, va, i, cmp);
	}
	return ((ret == -1 ? ret : i));
}
