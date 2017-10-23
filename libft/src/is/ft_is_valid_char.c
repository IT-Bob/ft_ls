/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 11:54:53 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/05 14:38:35 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** is_valid_char() reçoit en paramètre une chaîne de caractères (utilisée pour
** lister les caractères autorisés) et le caractère à tester.
** La fonction renvoie 1 si c est un caractère valide, 0 s'il ne l'est pas et
** -1 si la chaîne envoyée est NULL.
*/

int	ft_is_valid_char(char *valid, char c)
{
	int	i;

	i = 0;
	if (!valid)
		return (-1);
	while (valid[i])
		if (c == valid[i++])
			return (1);
	return (0);
}
