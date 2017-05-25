/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 20:41:46 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/25 20:44:02 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*just_name(char *path)
{
	int	i;
	int	find;

	i = -1;
	find = 0;
	while (path[++i])
		if (path[i] == '/')
			find = i + 1;
	return (&path[find]);
}

void	put_error(t_elem *elem, t_ls *ls)
{
	char	*name;

	name = just_name(elem->name);
	ft_putstr_fd(NAME, 2);
	ft_putstr_fd(" :", 2);
	if (name[0])
		ft_putstr_fd(" ", 2);
	perror(name[0] ? name : " ");
	ls->error = 1;
}
