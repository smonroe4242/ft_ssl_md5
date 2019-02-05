/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 23:28:29 by smonroe           #+#    #+#             */
/*   Updated: 2018/08/08 22:34:33 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfr(char *s1, char const *s2)
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
			return (new);
		}
	return (NULL);
}
