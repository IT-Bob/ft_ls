/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:53:30 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/22 19:58:29 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_printf.h"

void	ls_files(t_elem **files, t_ls *ls)
{
	if (*files)
	{	
		if (ls && ls->flags[2] && ls->total > -1)
			ft_printf("total %d\n", ls->total);
		if (ls && ls->flags[3])
		{
			if (ls->flags[2])
				print_reverse_long(*files, ls);
			else
				ls_lstiter_reverse(*files, &print_name);
		}
		else
		{
			if (ls && ls->flags[2])
				print_standard_long(*files, ls);
			else
				ls_lstiter(*files, &print_name);
		}
		ls_lstdel(files);
		initialise_size(ls);
	}
}
