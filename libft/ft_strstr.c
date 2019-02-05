/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 23:10:31 by smonroe           #+#    #+#             */
/*   Updated: 2018/04/18 10:06:52 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	k;

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
			while (needle[j] && (haystack[i++] == needle[j]))
				j++;
			if (needle[j] == '\0')
				return (char *)(haystack + k);
			i = k;
		}
		i++;
	}
	return (NULL);
}
