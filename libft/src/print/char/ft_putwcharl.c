/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwcharl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:11:40 by aguerin           #+#    #+#             */
/*   Updated: 2017/06/28 17:06:00 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putwcharl permet d'afficher les caractères étendus, suivi d'un retour à la
** ligne.
*/

int	ft_putwcharl(long c)
{
	return (ft_putwchar(c) + ft_putchar('\n'));
}
