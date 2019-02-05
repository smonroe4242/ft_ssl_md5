/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:14:46 by smonroe           #+#    #+#             */
/*   Updated: 2018/04/20 19:30:54 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	size_t	b;
	char	*new;

	if (s && f)
	{
		i = -1;
		b = ft_strlen(s);
		if (!(new = ft_strnew(b)))
			return (NULL);
		while (s[++i])
			new[i] = f(s[i]);
		return (new);
	}
	return (NULL);
}
