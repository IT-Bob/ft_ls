/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:19:10 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/15 16:19:21 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	print(char out, int width, int left)
{
	int cmp;

	cmp = 0;
	if (!left)
		cmp += ft_putxchar(' ', width - 1);
	cmp += ft_putchar(out);
	if (left)
		cmp += ft_putxchar(' ', width - 1);
	return (cmp);
}

int			conversion_c(const char *format, va_list va, int *cmp)
{
	int	specifier[6];
	int	width;
	int	i;

	width = 0;
	i = find(format, specifier, &width, NULL);
	correction_specifier(specifier, 0, 0, 0);
	if ((find_length_modifier(&format[i])) == 3)
		return (conversion_c_cap(format, va, cmp));
	*cmp += print(va_arg(va, int), width, specifier[3]);
	return (1);
}
