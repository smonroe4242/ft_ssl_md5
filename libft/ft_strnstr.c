/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 23:19:03 by smonroe           #+#    #+#             */
/*   Updated: 2018/04/18 01:49:39 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (needle[0] == '\0')
		return (char *)(haystack);
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			k = i;
			while (i < len && needle[j] != '\0' && needle[j] == haystack[i++])
				j++;
			if (needle[j] == '\0')
				return ((char *)haystack + k);
			i = k;
		}
		i++;
	}
	return (NULL);
}
