/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:34:46 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/29 13:39:25 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** ft_perror() affiche le message d'erreur et quitte le programme avec la valeur
** envoyée en paramètre si celle-ci est différente de 0.
*/

void	ft_perror(const char *message, const int value)
{
	ft_putendl_fd(message, 2);
	if (value)
		exit(value);
}
