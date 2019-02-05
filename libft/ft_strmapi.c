/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:20:51 by smonroe           #+#    #+#             */
/*   Updated: 2018/04/20 19:30:57 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		b;
	char	*new;

	if (s && f)
	{
		b = ft_strlen(s);
		if (!(new = ft_strnew(b)))
			return (NULL);
		i = -1;
		while (s[++i])
			new[i] = f(i, s[i]);
		return (new);
	}
	return (NULL);
}
