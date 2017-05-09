/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:07:30 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/09 17:09:50 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_name(t_elem *elem)
{
	ft_putendl(elem->name);
}

void	print_path(t_elem *elem)
{
	ft_putendl(elem->path);
}
