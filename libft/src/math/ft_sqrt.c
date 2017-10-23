/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:54:50 by aguerin           #+#    #+#             */
/*   Updated: 2017/06/21 14:28:54 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_sqrt() renvoie la racine de nb.
*/

int		ft_sqrt(int nb)
{
	int ope;

	ope = 2;
	if (nb == 1)
		return (1);
	else if (nb > 0)
	{
		while (ope * ope < nb)
			ope++;
		if (ope * ope == nb)
			return (ope);
	}
	return (0);
}
