/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwnchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:10:49 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/15 11:11:07 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_putwnchar() affiche les n premiers caractères de la chaîne str.
** Si n est plus grand que la taille de la chaîne, l'affichage s'arrête en fin
** de chaîne.
** Si str est NULL, la fonction quitte en indiquant une erreur.
** La fonction renvoie le nombre de caractères affichés.
*/

#include "libft.h"

int	ft_putwnchar(wchar_t *str, unsigned int n)
{
	int	cmp;

	if (!str)
		return (-1);
	cmp = 0;
	while (*str && n-- > 0)
		cmp += ft_putwchar(*(str++));
	return (cmp);
}
