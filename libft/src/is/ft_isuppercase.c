/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isuppercase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:43:36 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/14 14:43:37 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isuppercase() renvoie 1
** si le caractère donné en paramètre est une lettre majuscule.
*/

int	ft_isuppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
