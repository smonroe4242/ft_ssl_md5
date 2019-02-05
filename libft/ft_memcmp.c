/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 08:21:28 by smonroe           #+#    #+#             */
/*   Updated: 2018/04/23 03:33:05 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = -1;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (++i < n)
		if (a[i] != b[i])
			return (a[i] - b[i]);
	return (0);
}
