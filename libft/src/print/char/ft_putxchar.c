/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 00:10:25 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/17 00:10:39 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_putxchar() affiche x fois le caractère c.
*/

#include <unistd.h>

int	ft_putxchar(char c, int x)
{
	int	i;

	i = -1;
	while (++i < x)
		write(1, &c, 1);
	return (i);
}
