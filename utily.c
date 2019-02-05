/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utily.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 23:02:20 by smonroe           #+#    #+#             */
/*   Updated: 2018/11/26 11:41:51 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void			r_format(char *hash, char *arg, t_flag f)
{
	if (f.p == 0)
	{
		if (f.r == 0)
		{
			if (f.s == 1)
				ft_printf("%s (\"%s\") = ", hash, arg);
			else
				ft_printf("%s (%s) = ", hash, arg);
		}
		else
		{
			if (f.s == 1)
				ft_printf(" \"%s\"", arg);
			else
				ft_printf(" %s", arg);
		}
	}
}

unsigned char	*pad(unsigned char *m, uint64_t len, uint16_t flip, t_hash hash)
{
	unsigned char	*out;
	unsigned char	*p;
	uint32_t		l;

	l = len % 64;
	out = (unsigned char *)ft_memalloc(64);
	p = out;
	ft_memcpy(out, m, 64);
	p[l] = (flip == 1) ? 0 : 0x80;
	p += 56;
	len = (hash == md5) ? (len << 3) : endian_swap_64(len << 3);
	ft_memcpy(p, &len, 8);
	free(m);
	return (out);
}
