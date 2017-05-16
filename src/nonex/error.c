/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 20:07:20 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/16 14:06:41 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_printf.h"

void	print_nonex(t_list *list, t_ls *ls)
{
	while (list)
	{
		ft_putstr_fd(NAME, 2);
		ft_putstr_fd(": ", 2);
		perror((char*)list->content);
		list = list->next;
		ls->error = 1;
	}
}
