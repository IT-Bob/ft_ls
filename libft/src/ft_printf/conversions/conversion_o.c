/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:28:15 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/15 16:28:26 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
** conversion pour %o ou %O
*/

static void	correction_o(int specifier[], int size[], int nb)
{
	if ((size[1] > 1 && specifier[0]) ||
		(!nb && specifier[0] && size[1] >= 0))
		specifier[0] = 0;
}

int			conversion_o(const char *format, va_list va, int *cmp, char c)
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
	if (c == 'o')
		nb = length_modifier_oux(i, va);
	else
		nb = length_modifier_dou_cap(i, va);
	correction_o(specifier, size, nb);
	correction_specifier(specifier, 1, 1, 0);
	if (size[1])
		specifier[1] = 0;
	if ((!nb && (size[1] == -1)))
		str = NULL;
	else if (!(str = ft_itoa_base(nb, 8)))
		return (-1);
	*cmp += print_r(str, size[0], size[1], specifier);
	ft_strdel(&str);
	return (1);
}
