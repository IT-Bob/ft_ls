/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:41:16 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/16 17:41:34 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** init_specifier_tab() initialise le tableau de specifier à 0.
*/

static void	init_specifier_tab(int specifier[])
{
	int	i;

	i = 0;
	while (i < 6)
		specifier[i++] = 0;
}

/*
** 0 = '#', 1 = '0', 2 = ' ', 3 = '-', 4 = '+', 5 = 1 pour négatif, 0 positif
** Lorsqu'un specifier est trouvé dans le format, la case correspondante dans le
** tableau de specifier est mise à 1.
*/

static int	find_specifier(const char *format, int specifier[])
{
	int	i;

	i = 0;
	init_specifier_tab(specifier);
	while (format[++i])
	{
		if (format[i] == '#')
			specifier[0] = 1;
		else if (format[i] == '0')
			specifier[1] = 1;
		else if (format[i] == ' ')
			specifier[2] = 1;
		else if (format[i] == '-')
			specifier[3] = 1;
		else if (format[i] == '+')
			specifier[4] = 1;
		else
			break ;
	}
	if (specifier[3])
		specifier[1] = 0;
	if (specifier[4])
		specifier[2] = 0;
	return (i);
}

/*
** find_width_prec() trouve les valeurs de width et precision dans le format.
*/

static int	find_width_prec(const char *format, int *wp, int begin, int is_prec)
{
	int	i;
	int	ret;

	i = 0;
	if (wp)
	{
		if (is_prec && format[begin] == '.')
		{
			begin += 1;
			i += 1;
			*wp = -1;
		}
		if (ft_isdigit(format[begin]))
		{
			if ((ret = ft_atoi(&format[begin])) < 0)
				*wp = 0;
			else if (ret > 0)
				*wp = ret;
		}
	}
	while (ft_isdigit(format[begin++]))
		i++;
	return (i);
}

/*
** find() fait appel aux différentes fonctions devant trouver les specifiers,
** width et la precision.
*/

int			find(const char *format, int specif[], int *width, int *precision)
{
	int	i;

	i = 0;
	i = find_specifier(format, specif);
	i += find_width_prec(format, width, i, 0);
	i += find_width_prec(format, precision, i, 1);
	if (precision && *precision)
		specif[1] = 0;
	return (i);
}
