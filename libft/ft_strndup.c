/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 22:07:02 by smonroe           #+#    #+#             */
/*   Updated: 2018/08/23 22:13:11 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *s, int i)
{
	char	*tmp;

	if (!s)
		return (NULL);
	tmp = ft_strnew(i);
	ft_memcpy(tmp, s, i);
	return (tmp);
}
