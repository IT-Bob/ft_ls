/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:16:21 by aguerin           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/05/18 16:35:47 by aguerin          ###   ########.fr       */
=======
/*   Updated: 2017/05/18 14:23:29 by aguerin          ###   ########.fr       */
>>>>>>> 0698bc3a845cd08614e7058f9f5f98619a24c150
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

void	ls_lstdelone(t_elem **elem)
{
	if (elem)
	{
<<<<<<< HEAD
		if ((*elem)->name)
			free((*elem)->name);
		(*elem)->name = NULL;
		if ((*elem)->path)
			free((*elem)->path);
		(*elem)->name = NULL;
=======
		if ((*elem)->path)
			free((*elem)->path);
		(*elem)->path = NULL;
>>>>>>> 0698bc3a845cd08614e7058f9f5f98619a24c150
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
