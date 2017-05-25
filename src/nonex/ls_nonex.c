/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_nonex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:54:17 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/25 20:49:26 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

static void	del(void *content, size_t size)
{
	if (size)
		;
	if (content)
		free(content);
	content = NULL;
}

static void	print_nonex(t_list *list)
{
	while (list)
	{
		ft_putstr_fd(NAME, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd((char*)list->content, 2);
		ft_putendl_fd(": No such file or directory", 2);
		list = list->next;
	}
}

void		ls_nonex(t_list **nonex)
{
	if (*nonex)
	{
		print_nonex(*nonex);
		ft_lstdel(nonex, &del);
	}
}
