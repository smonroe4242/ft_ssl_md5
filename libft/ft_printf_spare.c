/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 03:38:03 by smonroe           #+#    #+#             */
/*   Updated: 2018/08/24 11:16:01 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wide(int i)
{
	char	*tmp;

	if (i <= 0x7f)
	{
		tmp = ft_strnew(1);
		ft_memcpy(tmp, &i, 1);
	}
	else if (i <= 0x7ff)
	{
		tmp = ft_strnew(2);
		ft_memcpy(tmp, &i, 2);
	}
	else if (i <= 0xffff)
	{
		tmp = ft_strnew(2);
		ft_memcpy(tmp, &i, 2);
	}
	else if (i <= 0x10ffff)
	{
		tmp = ft_strnew(2);
		ft_memcpy(tmp, &i, 2);
	}
	else
		tmp = ft_strnew(0);
	return (tmp);
}

char	*ft_wider(int *s)
{
	char	*buf;
	int		i;

	i = 0;
	buf = ft_wide(s[i++]);
	while (s[i] && i < 10)
		buf = ft_strmrg(buf, ft_wide(s[i++]));
	return (buf);
}

char	*string(t_var v)
{
	if (v.prec)
		v.str[v.prec] = 0;
	if (v.pad)
	{
		if (v.neg)
			while ((int)ft_strlen(v.str) < v.pad)
				v.str = ft_strjoinfr(v.str, " ");
		if (!v.neg)
			while ((int)ft_strlen(v.str) < v.pad)
				v.str = ft_strappfr(" ", v.str);
	}
	return (v.str);
}
