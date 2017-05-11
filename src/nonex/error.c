/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 20:07:20 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/11 17:00:27 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_printf.h"

void	print_nonex(t_list *list, t_ls *ls)
{
	while (list)
	{
		put_error(list->content, ls);
		list = list->next;
	}
}
