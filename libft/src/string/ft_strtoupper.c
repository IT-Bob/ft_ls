/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 11:21:17 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/22 11:21:48 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strtoupper() prend en entrée une chaîne allouée dynamiquement
** et transforme les lettres minuscules qui la composent en majuscules.
*/

#include "libft.h"

char	*ft_strtoupper(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = -1;
	while (str[++i])
		str[i] = ft_toupper(str[i]);
	return (str);
}
