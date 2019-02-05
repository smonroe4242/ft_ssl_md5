/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 22:37:48 by smonroe           #+#    #+#             */
/*   Updated: 2018/04/18 14:10:14 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (dst[i] && i <= dstsize)
		i++;
	k = i;
	if (dstsize != 0 && k < dstsize)
	{
		while (j < dstsize - k - 1 && src[j])
			dst[i++] = src[j++];
	}
	if (i < dstsize)
	{
		dst[i] = '\0';
		return (ft_strlen(src) + k);
	}
	return (dstsize + ft_strlen(src));
}
