/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:32:06 by aguerin           #+#    #+#             */
/*   Updated: 2016/11/07 12:37:26 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isalnum() renvoie 1
** si le caractère donné en paramètre est un chiffre ou une lettre.
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
