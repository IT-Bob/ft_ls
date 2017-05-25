/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:53:21 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/25 13:17:23 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	fill_size(t_elem *elem, t_ls *ls, int blocks)
{
	if (elem && ls)
	{
		elem->user_len = ft_strlen(elem->user);
		if (elem->user_len > ls->user_mlen)
			ls->user_mlen = elem->user_len;
		elem->grp_len = ft_strlen(elem->grp);
		if (elem->grp_len > ls->grp_mlen)
			ls->grp_mlen = elem->grp_len;
		elem->link_len = ft_nbrlen(elem->link);
		if (elem->link_len > ls->link_mlen)
			ls->link_mlen = elem->link_len;
		elem->size_len = ft_nbrlen(elem->size);
		if (elem->size_len > ls->size_mlen)
			ls->size_mlen = elem->size_len;
		elem->majo_len = ft_nbrlen(elem->major);
		if (elem->majo_len > ls->majo_mlen)
			ls->majo_mlen = elem->majo_len;
		elem->mino_len = ft_nbrlen(elem->minor);
		if (elem->mino_len > ls->mino_mlen)
			ls->mino_mlen = elem->mino_len;
		if (ls->majo_mlen + ls->mino_mlen > ls->size_mlen)
			ls->size_mlen = ls->majo_mlen + ls->mino_mlen + 2;
		ls->total += blocks;
	}
}

t_elem	*add_files(t_elem *files, char *name, t_ls *ls, struct stat s)
{
	t_elem	*elem;

	elem = ls_lstnew(name, NULL, s, ls);
	if (ls && ls->total == -1)
		ls->total = 0;
	if (ls->flags[2])
		fill_size(elem, ls, s.st_blocks);
	if (ls && ls->flags[4])
		files = ls_lstaddtime(&files, elem);
	else
		files = ls_lstaddalpha(&files, elem);
	if (ls)
		ls->nb_files = 1;
	return (files);
}

t_elem	*add_files_path(t_elem *f, char *path, t_ls *ls, struct stat s)
{
	t_elem	*elem;

	elem = ls_lstnew(just_name(path), path, s, ls);
	if (ls->flags[2])
		fill_size(elem, ls, s.st_blocks);
	if (ls && ls->flags[4])
		f = ls_lstaddtime(&f, elem);
	else
		f = ls_lstaddalpha(&f, elem);
	if (ls)
		ls->nb_files = 1;
	return (f);
}
