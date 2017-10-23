/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguerin <aguerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 10:19:26 by aguerin           #+#    #+#             */
/*   Updated: 2016/11/21 10:53:02 by aguerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_count_word() renvoie le nombre de mots trouvés dans la chaîne s.
** Le caractère c est le caractère de séparation des mots.
*/

unsigned int	ft_count_word(char *s, char c)
{
	int	i;
	int	cmp;
	int	word;

	i = 0;
	cmp = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && !word)
		{
			cmp++;
			word = 1;
		}
		else if (s[i] == c)
			word = 0;
		i++;
	}
	return (cmp);
}
