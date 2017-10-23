/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 17:05:44 by aguerin           #+#    #+#             */
/*   Updated: 2017/04/03 17:05:47 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
** print_r() et print_l() s'occupent de l'affichage pour les conversions
** numériques (%d %i %o %u %x).
** print_l() est appelée lorsque l'affichage doit se faire le plus à gauche
** (avec le specifier '-' d'indiqué).
*/

static int	print_l(const char *out, int width, int precision, int specifier[])
{
	int	cmp;

	cmp = 0;
	if (specifier[0] == 2)
		cmp += ft_putstr("0x");
	else if (specifier[0] == 3)
		cmp += ft_putstr("0X");
	else if (specifier[0])
		cmp += ft_putchar('0');
	if (specifier[2] && !specifier[5])
		cmp += ft_putchar(' ');
	if (specifier[4] || specifier[5])
		cmp += ft_putchar((specifier[5] ? '-' : '+'));
	cmp += ft_putxchar('0', precision);
	cmp += (out ? ft_putstr(out) : 0);
	cmp += ft_putxchar(' ', width);
	return (cmp);
}

int			print_r(const char *out, int width, int precision, int specifier[])
{
	int	cmp;

	if (adjust(&width, &precision, out, specifier))
		out++;
	if (specifier[3])
		return (print_l(out, width, precision, specifier));
	cmp = 0;
	if (!specifier[1])
		cmp += ft_putxchar(' ', width);
	if (specifier[0] == 2)
		cmp += ft_putstr("0x");
	else if (specifier[0] == 3)
		cmp += ft_putstr("0X");
	else if (specifier[0])
		cmp += ft_putchar('0');
	if (specifier[2] && !specifier[5])
		cmp += ft_putchar(' ');
	if (specifier[4] || specifier[5])
		cmp += ft_putchar((specifier[5] ? '-' : '+'));
	if (specifier[1])
		cmp += ft_putxchar('0', width);
	cmp += ft_putxchar('0', precision);
	cmp += (out ? ft_putstr(out) : 0);
	return (cmp);
}
