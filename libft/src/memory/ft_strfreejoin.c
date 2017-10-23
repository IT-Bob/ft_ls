/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfreejoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 10:05:57 by aguerin           #+#    #+#             */
/*   Updated: 2017/09/12 17:28:41 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Identique a ft_strjoin, mais libère la mémoire de s1.
*/

char			*ft_strfreejoin(char *s1, char *s2)
{
	char	*str;
	int		len;

	len = (s1 ? ft_strlen(s1) : 0) + (s2 ? ft_strlen(s2) : 0);
	if ((str = ft_strnew(len)))
	{
		len = 0;
		while (s1 && s1[len])
		{
			str[len] = s1[len];
			len++;
		}
		while (*s2)
		{
			str[len++] = *s2;
			s2++;
		}
		str[len] = '\0';
		if (s1)
			ft_strdel(&s1);
		return (str);
	}
	return (NULL);
}
