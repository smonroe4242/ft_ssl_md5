/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappfr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:12:56 by smonroe           #+#    #+#             */
/*   Updated: 2018/08/09 15:16:51 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappfr(char *s1, char *s2)
{
	char	*new;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = ft_strnew(len)))
		return (NULL);
	if ((new = ft_strncat(new, s1, len)))
		if ((new = ft_strncat(new, s2, len)))
		{
			free(s2);
			return (new);
		}
	return (NULL);
}
