/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corrections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 15:50:58 by aguerin           #+#    #+#             */
/*   Updated: 2017/04/03 15:51:19 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** correction_specifier() règle les conflits de specifiers incompatibles.
*/

void	correction_specifier(int specifier[], int nb, int ox, int d)
{
	if (!ox)
		specifier[0] = 0;
	if (!nb)
		specifier[1] = 0;
	if (!d)
	{
		specifier[2] = 0;
		specifier[4] = 0;
	}
}

/*
** adjust() et wadjust() recalculent la taille de width et precision en fonction
** des specifiers indiqués et de la taille de la chaîne (ou nombre) à afficher.
*/

int		adjust(int *width, int *precision, const char *out, int specifier[])
{
	int	length;

	if (out && specifier[5])
		out++;
	length = (out ? ft_strlen(out) : 0);
	*precision = (*precision < length ? 0 : *precision);
	*width = (*width < length ? 0 : *width);
	*precision = *precision - length;
	*precision = (*precision < 0 ? 0 : *precision);
	*width = (*width < 0 ? 0 : *width);
	*width = *width - *precision - length - (specifier[4] || specifier[5]);
	if (specifier[0] == 2 || specifier[0] == 3)
		*width -= 2;
	else if (specifier[0])
		*width -= 1;
	if (specifier[2] && !specifier[5])
		*width -= 1;
	*width = (*width < 0 ? 0 : *width);
	return (specifier[5]);
}

int		wadjust(int *width, wchar_t *out, int specifier[])
{
	int	length;

	if (out && specifier[5])
		out++;
	length = (out ? ft_strwbytlen(out) : 0);
	*width = (*width < length ? 0 : *width);
	*width = (*width < 0 ? 0 : *width);
	*width = *width - length - (specifier[4] || specifier[5]);
	if (specifier[0] == 2 || specifier[0] == 3)
		*width -= 2;
	else if (specifier[0])
		*width -= 1;
	if (specifier[2] && !specifier[5])
		*width -= 1;
	*width = (*width < 0 ? 0 : *width);
	return (specifier[5]);
}
