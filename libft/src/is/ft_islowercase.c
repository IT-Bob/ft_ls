/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islowercase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:43:14 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/14 14:43:16 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_islowercase() renvoie 1
** si le caractère donné en paramètre est une lettre minuscule.
*/

int	ft_islowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
