/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 11:21:55 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/22 11:22:08 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strtolower() prend en entrée une chaîne allouée dynamiquement
** et transforme les lettres majuscules qui la composent en minuscules.
*/

#include "libft.h"

char	*ft_strtolower(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	return (str);
}
