/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:42:10 by aguerin           #+#    #+#             */
/*   Updated: 2016/11/21 11:13:33 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst1;
	char	*src1;

	i = 0;
	dst1 = (char*)dst;
	src1 = (char*)src;
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst);
}
