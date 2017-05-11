/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 20:07:20 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/11 09:24:16 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_printf.h"

void	print_nonex(t_list *list)
{
	while (list)
	{
		ft_printf("%s: %s: No such file or directory\n", NAME, list->content);
		list = list->next;
	}
}
