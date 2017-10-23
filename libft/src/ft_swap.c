/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:59:54 by aguerin           #+#    #+#             */
/*   Updated: 2017/08/24 09:30:41 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** \brief	ft_swap() échange le contenu de deux pointeurs.
**
** \param	a	- premier pointeur
** \param	b	- deuxième pointeur
*/

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
