/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c_cap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:22:43 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/15 16:22:56 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	print(wchar_t out, int width, int left)
{
	int	cmp;

	cmp = 0;
	if (!left)
		cmp += ft_putxchar(' ', width - ft_charwbytlen(out));
	cmp += ft_putwchar(out);
	if (left)
		cmp += ft_putxchar(' ', width - ft_charwbytlen(out));
	return (cmp);
}

int			conversion_c_cap(const char *format, va_list va, int *cmp)
{
	int		specifier[6];
	int		width;

	width = 0;
	find(format, specifier, &width, NULL);
	*cmp += print(va_arg(va, wchar_t), width, specifier[3]);
	return (1);
}
