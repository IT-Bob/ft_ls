/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:23:35 by aguerin           #+#    #+#             */
/*   Updated: 2016/11/07 15:32:15 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isspace() renvoie 1
** si le caractère donné en paramètre représente un espace blanc.
*/

int	ft_isspace(int c)
{
	if ((c == '\t') || (c == '\n') || (c == '\v') ||
		(c == '\f') || (c == '\r') || (c == ' '))
		return (1);
	return (0);
}
