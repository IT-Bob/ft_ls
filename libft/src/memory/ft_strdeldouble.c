/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdeldouble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:57:30 by aguerin           #+#    #+#             */
/*   Updated: 2017/08/23 14:44:06 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strdeldouble() libère la mémoire du double pointeur str
*/

void	ft_strdeldouble(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			ft_strdel(&str[i++]);
		ft_memdel((void**)&str);
	}
}
