/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:53:30 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/11 15:53:36 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	ls_files(t_elem **files, t_ls *ls)
{
	if (*files)
	{
		if (ls && ls->flags[3])
			ls_lstiter_reverse(*files, &print_name);
		else
			ls_lstiter(*files, &print_name);
		ls_lstdel(files);
	}
}
