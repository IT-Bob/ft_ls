/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:06:42 by aguerin           #+#    #+#             */
/*   Updated: 2016/11/09 14:07:20 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_putcharl() affiche le caractère envoyé en paramètre, suivi d'un retour à
** la ligne et renvoie le nombre de caractères affichés.
*/

#include "libft.h"

int	ft_putcharl(char c)
{
	return (ft_putchar(c) + ft_putchar('\n'));
}
