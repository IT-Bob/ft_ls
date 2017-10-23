/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:10:29 by aguerin           #+#    #+#             */
/*   Updated: 2017/06/28 17:21:30 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche le nombre 'n' sur la sortie standard suivi d'un retour à la ligne
** et retourne le nombre de caractères affichés.
*/

int	ft_putnbrl(int n)
{
	return (ft_putnbr(n) + ft_putchar('\n'));
}
