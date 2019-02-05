/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mdfive.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 02:20:14 by smonroe           #+#    #+#             */
/*   Updated: 2018/11/26 06:36:08 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void		digest_md5(uint32_t *l)
{
	int		n;
	int		i;
	char	c;
	char	*hex;

	hex = "0123456789abcdef";
	n = 3;
	while (++n < 8)
	{
		i = -1;
		l[n] = endian_swap(l[n]);
		while (++i < 8)
		{
			c = hex[(l[n] << (i << 2)) >> 28];
			write(1, &c, 1);
		}
	}
}

uint32_t	*mdfive_round(uint32_t *m, uint32_t *l,
							uint32_t *k, uint32_t *s)
{
	uint32_t	f;
	uint32_t	g;
	int			i;

	i = -1;
	while (++i < 64)
	{
		if (i >= 0 && i <= 15)
			f = ((l[1] & l[2]) | (~l[1] & l[3]));
		else if (i >= 16 && i <= 31)
			f = ((l[3] & l[1]) | (~l[3] & l[2]));
		else
			f = (i <= 47) ? (l[1] ^ l[2] ^ l[3]) : (l[2] ^ (l[1] | ~l[3]));
		if (i >= 0 && i <= 31)
			g = (i <= 15) ? (i) : ((i << 2) + i + 1) & 15;
		else
			g = (i <= 47) ? (((i << 1) + i + 5) & 15) : (((i << 3) - i) & 15);
		f += l[0] + k[i] + m[g];
		l[0] = l[3];
		l[3] = l[2];
		l[2] = l[1];
		l[1] += ((f << s[i]) | f >> (32 - s[i]));
	}
	return (l);
}

uint32_t	*chunk(unsigned char *m)
{
	uint32_t	*w;

	if (!m)
		return (NULL);
	if ((w = (uint32_t *)ft_memalloc(sizeof(uint32_t) << 4)) == NULL)
	{
		free(m);
		return (NULL);
	}
	ft_memcpy(w, m, 64);
	free(m);
	return (w);
}

void		mdfive(uint32_t *k, uint32_t *s, uint32_t *l, t_in man)
{
	uint32_t	*m;

	while ((m = chunk(get_ret(man))))
	{
		l[0] = l[4];
		l[1] = l[5];
		l[2] = l[6];
		l[3] = l[7];
		l = mdfive_round(m, l, k, s);
		l[4] = (l[4] + l[0]) & 0xffffffff;
		l[5] = (l[5] + l[1]) & 0xffffffff;
		l[6] = (l[6] + l[2]) & 0xffffffff;
		l[7] = (l[7] + l[3]) & 0xffffffff;
		free(m);
	}
	digest_md5(l);
}

void		mdfive_init(t_in man)
{
	uint32_t	*k;
	uint32_t	*s;
	uint32_t	*l;

	k = init_k();
	s = init_s();
	l = (uint32_t *)malloc(sizeof(uint32_t) << 3);
	l[4] = 0x67452301;
	l[5] = 0xefcdab89;
	l[6] = 0x98badcfe;
	l[7] = 0x10325476;
	man.hash = md5;
	man.bytes = 64;
	mdfive(k, s, l, man);
	free(l);
	free(s);
	free(k);
}
