/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:11:53 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/25 09:51:35 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

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

static void	fill_flags_tab(char *argv, int flags[])
{
	int	i;
	int	j;

	j = -1;
	while (argv[++j] && ((i = is_valid_flag(FLAGS, argv[j])) >= 0))
		flags[i] = 1;
	if (i == -1)
		illegal_option(argv[j]);
}

int			find_flags(char **argv, int flags[])
{
	int	i;

	i = -1;
	if (!argv || !flags)
		exit(-1);
	while (argv && argv[++i] && argv[i][0] == '-')
	{
		if (!argv[i][1])
			return (i);
		else if (argv[i][1] == '-' && !argv[i][2])
			return (++i);
		fill_flags_tab(&argv[i][1], flags);
	}
	return (i);
}
