/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 19:58:46 by smonroe           #+#    #+#             */
/*   Updated: 2018/04/21 15:39:56 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	if (!(s))
		return (NULL);
	i = 0;
	if (!(sub = ft_strnew(len)))
		return (NULL);
	len += start;
	while (start < len && s[start] != '\0')
		sub[i++] = s[start++];
	if (start != len)
		return (NULL);
	sub[i] = '\0';
	return (sub);
}
