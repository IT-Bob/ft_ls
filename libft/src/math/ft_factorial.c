/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:12:20 by aguerin           #+#    #+#             */
/*   Updated: 2017/06/21 14:28:01 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_factorial() renvoie la factorielle de nb.
*/

int	ft_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	else
		return (nb * ft_factorial(nb - 1));
}
