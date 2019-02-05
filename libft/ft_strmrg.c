/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmrg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 02:46:46 by smonroe           #+#    #+#             */
/*   Updated: 2018/08/24 11:05:05 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmrg(char *s1, char *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	if (!(new = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	if ((new = ft_strncat(new, s1, ft_strlen(s1) + ft_strlen(s2))))
		if ((new = ft_strncat(new, s2, ft_strlen(s1) + ft_strlen(s2))))
		{
			free(s1);
			free(s2);
			return (new);
		}
	return (NULL);
}
