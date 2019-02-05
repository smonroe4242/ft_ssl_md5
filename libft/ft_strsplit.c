/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 20:13:34 by smonroe           #+#    #+#             */
/*   Updated: 2018/08/25 12:47:58 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_make_2d(char const *s, char **bloc, char c)
{
	int	i;
	int	w;
	int	l;

	w = 0;
	i = 0;
	while (s[i])
	{
		l = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			l++;
		}
		if (l)
			if (!(bloc[w++] = ft_strnew(l + 1)) && s[i])
				return (NULL);
	}
	return (bloc);
}

static char	ft_word_count(char const *s, char c)
{
	int words;
	int i;

	i = 0;
	words = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
			words++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	int		w;
	int		l;
	char	**bloc;

	if (!(s && c))
		return (NULL);
	if (!(bloc = (char **)malloc(sizeof(char *) * (ft_word_count(s, c)))))
		return (NULL);
	if (!(bloc = ft_make_2d(s, bloc, c)))
		return (NULL);
	w = 0;
	while (*s)
	{
		l = 0;
		while (*s == c && *s)
			s += 1;
		while (*s != c && *s)
			bloc[w][l++] = *s++;
		if (l)
			bloc[w++][l] = '\0';
	}
	bloc[w] = 0;
	return (bloc);
}
