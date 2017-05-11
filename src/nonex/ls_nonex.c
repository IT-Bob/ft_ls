/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_nonex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:54:17 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/11 15:54:27 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	ls_nonex(t_list **nonex)
{
	if (*nonex)
	{
		print_nonex(*nonex);
		ft_lstdel(nonex, &del);
	}
}
