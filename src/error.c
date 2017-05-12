/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>           +#+  +:+       +#          */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:48:03 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/12 15:51:02 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	put_error(t_elem *elem, t_ls *ls)
{
	char	*name;

	name = just_name(elem->name);
	ft_putstr_fd(NAME, 2);
	ft_putstr_fd(":", 2);
	if (name[0])
		ft_putstr_fd(" ", 2);
	perror(name[0] ? name : " ");
	ls->error = 1;
}
