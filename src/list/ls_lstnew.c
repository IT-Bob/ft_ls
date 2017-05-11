/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:23:40 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/11 12:38:20 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>

/*
** ls_lstnew() alloue la mémoire et initialise la structure pour la liste de ls.
*/

t_elem	*ls_lstnew(char *name, struct stat stat)
{
	t_elem	*element;

	if ((element = (t_elem*)ft_memalloc(sizeof(t_elem))))
	{
		if ((element->name = (name ? ft_strnew(ft_strlen(name)) : NULL)))
			element->name = ft_strcpy(element->name, name);
		element->stat = stat;
		element->next = NULL;
	}
	return (element);
}
