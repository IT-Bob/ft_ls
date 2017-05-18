/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>           +#+  +:+       +#          */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:48:03 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/18 12:42:54 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char *just_name(char *name)
{
	int	i;
	int	find;

	i = -1;
	find = 0;
	while (name[++i])
		if (name[i] == '/')
			find = i + 1;
	return (&name[find]);
}

void		put_error(t_elem *elem, t_ls *ls)
{
	char	*name;
	
	  name = just_name(elem->name);
	ft_putstr_fd(NAME, 2);
	ft_putstr_fd(":", 2);
	if (name[0])
		ft_putstr_fd(" ", 2);
	perror(name[0] ? name : " ");
	ls->error = 1;
}
