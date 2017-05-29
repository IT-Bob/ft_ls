/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:11:53 by aguerin           #+#    #+#             */
/*   Updated: 2017/05/29 14:02:43 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

/*
** illegal_option() est appelée lorsqu'un flag incorrect est renseigné.
** Elle affiche sur la sortie d'erreur un message et l'usage de ft_ls
** puis quitte le programme avec la valeur -1.
*/

static void	illegal_option(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ", 2);
	ft_putstr_fd(NAME, 2);
	ft_putstr_fd(" [-", 2);
	ft_putstr_fd(FLAGS_LIST, 2);
	ft_putstr_fd("] [file ...]\n", 2);
	exit(-1);
}

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

/*
** find_flags() cherche les flags envoyés dans les paramètres de argv.
** La fonction renvoie l'indice de l'élément suivant le dernier flag trouvé.
*/


int			find_flags(char **argv, int flags[])
{
	int	i;

	if (!argv || !flags)
		ft_perror("Paramètre NULL - find_flags()", -1);
	i = -1;
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
