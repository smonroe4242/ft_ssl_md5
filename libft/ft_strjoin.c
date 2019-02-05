/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 19:59:00 by smonroe           #+#    #+#             */
/*   Updated: 2018/04/21 15:42:57 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	if (!(new = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	if ((new = ft_strncat(new, s1, ft_strlen(s1) + ft_strlen(s2))))
		if ((new = ft_strncat(new, s2, ft_strlen(s1) + ft_strlen(s2))))
			return (new);
	return (NULL);
}
