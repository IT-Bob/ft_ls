/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:16:21 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/09 17:52:17 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

void	ls_lstdelone(t_elem **elem)
{
	if (elem && *elem)
	{
		if ((*elem)->name)
			free((*elem)->name);
		(*elem)->name = NULL;
		if ((*elem)->path)
			free((*elem)->path);
		(*elem)->path = NULL;
		if (*elem)
			free(elem);
		elem = NULL;
	}
}

void	ls_lstdel(t_elem **elem)
{
	if (*elem)
	{
		ls_lstdel(&((*elem)->next));
		ls_lstdelone(&(*elem));
	}
}
