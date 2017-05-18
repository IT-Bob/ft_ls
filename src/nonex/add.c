/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:53:49 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/18 14:15:37 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*add_nonex(t_list *nonex, char *name, t_ls *ls)
{
	nonex = ft_lstaddalpha(&nonex, ft_lstnew(name, ft_strlen(name) + 1));
	ls->error = 1;
	ls->nb_nonex = 1;
	return (nonex);
}
