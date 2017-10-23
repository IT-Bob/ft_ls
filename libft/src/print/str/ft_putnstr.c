/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 10:44:33 by aguerin           #+#    #+#             */
/*   Updated: 2017/06/06 17:39:39 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_putnstr() affiche les n premiers caractères de la chaîne str.
** Si n est plus grand que la taille de la chaîne, l'affichage s'arrête en fin
** de chaîne.
** Si str est NULL, la fonction quitte en indiquant une erreur.
** La fonction renvoie le nombre de caractères affichés.
*/

#include "libft.h"
#include <unistd.h>

int	ft_putnstr(const char *str, unsigned int n)
{
	unsigned int	len;

	if (!str)
		return (-1);
	len = 0;
	while (str[len] && len <= n)
		len++;
	if (n > len)
		n = len;
	return (write(1, str, n));
}
