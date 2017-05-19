/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:16:21 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/19 11:10:38 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

void	ls_lstdelone(t_elem **elem)
{
	if (elem)
	{
		if ((*elem)->name)
			free((*elem)->name);
		(*elem)->name = NULL;
		if ((*elem)->path)
			free((*elem)->path);
		(*elem)->name = NULL;
		if ((*elem)->user)
			free((*elem)->user);
		(*elem)->user = NULL;
		if ((*elem)->grp)
			free((*elem)->grp);
		(*elem)->grp = NULL;
		if ((*elem)->date)
			free((*elem)->date);
		(*elem)->date = NULL;
		free(*elem);
		*elem = NULL;
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
