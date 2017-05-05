/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:11:53 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/05 17:29:27 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_valid_flag(char *flags, char c)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static void	fill_flags_tab(char *flags, int tab[])
{
	int	i;
	int	j;

	j = -1;
	while (flags[++j] && ((i = is_valid_flag(FLAGS, flags[j])) >= 0))
		tab[i] = 1;
	if (i == -1)
		illegal_option(flags[j]);
}

int			find_flags(char **argv, t_ls ls)
{
	int	i;

	i = -1;
	while (argv[++i] && argv[i][0] == '-')
	{
		if (!argv[i][1])
			return (i);
		else if (argv[i][1] == '-')
			return (++i);
		fill_flags_tab(&argv[i][1], ls.tab);
	}
	return (i);
}
