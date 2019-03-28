/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:58:13 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/11/24 15:58:14 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_i(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int		ft_words(char const *str, char c)
{
	int words;
	int i;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			words++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (words);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	x;

	x = 0;
	tab = (char**)malloc(sizeof(char*) * (ft_words(s, c)));
	if (tab == NULL)
		return (0);
	tab[ft_words(s, c)] = NULL;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = 0;
		i = ft_i(s, c);
		if (i)
		{
			if ((tab[x] = ft_strnew(i)) == NULL)
				return (0);
			ft_strncpy(tab[x++], s, i);
			s = s + i;
		}
	}
	return (tab);
}
