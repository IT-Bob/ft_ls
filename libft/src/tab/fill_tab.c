/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:55:23 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/05 17:02:12 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** fill_tab() remplit le tableau d'entiers tab avec la valeur value.
*/

void	fill_tab(int tab[], unsigned int size, int value)
{
	unsigned int	i;

	i = 0;
	while (i < size)
		tab[i++] = value;
}
