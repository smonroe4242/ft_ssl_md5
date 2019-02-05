/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 06:35:14 by smonroe           #+#    #+#             */
/*   Updated: 2018/11/26 02:38:50 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void		digest_sha(uint32_t *h)
{
	char	*hex;
	char	c;
	int		i;
	int		n;

	hex = "0123456789abcdef";
	n = -1;
	while (++n < 8)
	{
		i = -1;
		while (++i < 8)
		{
			c = hex[(h[n] << (i << 2)) >> 28];
			write(1, &c, 1);
		}
	}
}

uint32_t	*sha_round(uint32_t *a, uint32_t *w, uint32_t *k)
{
	uint32_t	tmpa;
	uint32_t	tmpb;
	uint32_t	chr;
	uint32_t	chr2;
	int			i;

	i = -1;
	while (++i < 64)
	{
		chr = ((rrot(a[4], 6)) ^ (rrot(a[4], 11)) ^ (rrot(a[4], 25)));
		chr2 = ((a[4] & a[5]) ^ ((~a[4]) & a[6]));
		tmpa = (a[7] + chr + chr2 + k[i] + w[i]);
		tmpb = (((rrot(a[0], 2)) ^ (rrot(a[0], 13)) ^ (rrot(a[0], 22)))
		+ ((a[0] & a[1]) ^ (a[0] & a[2]) ^ (a[1] & a[2])));
		a[7] = a[6];
		a[6] = a[5];
		a[5] = a[4];
		a[4] = (a[3] + tmpa);
		a[3] = a[2];
		a[2] = a[1];
		a[1] = a[0];
		a[0] = (tmpa + tmpb);
	}
	return (a);
}

uint32_t	*chunk_sha(unsigned char *m)
{
	uint32_t	*w;
	int			i;

	if (!m || (w = (uint32_t *)ft_memalloc(256)) == NULL)
		return (NULL);
	ft_memcpy(w, m, 64);
	ft_memset(&w[16], 0, 192);
	free(m);
	i = -1;
	while (++i < 64)
		w[i] = endian_swap(w[i]);
	return (w);
}

void		sha_256_hash(uint32_t *h, uint32_t *k, t_in man)
{
	uint32_t	*a;
	uint32_t	*w;
	int			i;

	a = (uint32_t *)ft_memalloc(sizeof(uint32_t) << 3);
	while ((w = chunk_sha(get_ret(man))))
	{
		i = 15;
		while (++i < 64)
			w[i] = (w[i - 16] + ((rrot(w[i - 15], 7)) ^ (rrot(w[i - 15], 18))
			^ (w[i - 15] >> 3)) + w[i - 7] + ((rrot(w[i - 2], 17))
			^ (rrot(w[i - 2], 19)) ^ (w[i - 2] >> 10)));
		i = -1;
		while (++i < 8)
			a[i] = h[i];
		a = sha_round(a, w, k);
		i = -1;
		while (++i < 8)
			h[i] = (h[i] + a[i]);
		free(w);
	}
	digest_sha(h);
	free(a);
}

void		sha_256_init(t_in man)
{
	uint32_t	*h;
	uint32_t	*k;

	h = init_h_sha();
	k = init_k_sha();
	man.hash = sha256;
	man.bytes = 64;
	sha_256_hash(h, k, man);
	free(k);
	free(h);
}
