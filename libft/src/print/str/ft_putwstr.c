/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:21:33 by aguerin           #+#    #+#             */
/*   Updated: 2017/03/10 15:21:35 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

int	ft_putwstr(wchar_t *str)
{
	int	cmp;

	if (!str)
		return (-1);
	cmp = 0;
	while (*str)
		cmp += ft_putwchar(*(str++));
	return (cmp);
}
