/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 07:13:20 by smonroe           #+#    #+#             */
/*   Updated: 2018/11/28 22:54:11 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

uint32_t	*init_h_sha(void)
{
	uint32_t	*h;

	h = (uint32_t *)malloc(sizeof(uint32_t) << 3);
	h[0] = 0x6a09e667;
	h[1] = 0xbb67ae85;
	h[2] = 0x3c6ef372;
	h[3] = 0xa54ff53a;
	h[4] = 0x510e527f;
	h[5] = 0x9b05688c;
	h[6] = 0x1f83d9ab;
	h[7] = 0x5be0cd19;
	return (h);
}

uint32_t	*init_k_sha(void)
{
	uint32_t	*k;
	double		r;
	int			i;
	int			p;

	k = (uint32_t *)malloc(sizeof(uint32_t) << 6);
	i = -1;
	p = 2;
	while (++i < 64)
	{
		while (!ft_isprime(p))
			p++;
		r = pow((double)p, ((double)1 / (double)3));
		r -= (int)r;
		k[i] = (r * UMAX);
		p++;
	}
	return (k);
}

uint32_t	*init_k(void)
{
	uint32_t	*k;
	int			i;

	k = (uint32_t *)malloc(sizeof(uint32_t) << 6);
	i = -1;
	while (++i < 64)
		k[i] = (UMAX * fabs(sin(i + 1)));
	return (k);
}

uint32_t	*init_s(void)
{
	uint32_t	*s;
	int			i;

	s = (uint32_t *)malloc(sizeof(uint32_t) * 64);
	i = -1;
	while (++i < 64)
		s[i] = (uint32_t[4][4]){{7, 12, 17, 22},
								{5, 9, 14, 20},
								{4, 11, 16, 23},
								{6, 10, 15, 21}}[i >> 4][i & 3];
	return (s);
}

int			hash_verify(char **hash)
{
	char	*ptr;

	ptr = *hash;
	while (*ptr)
	{
		*ptr = ft_toupper(*ptr);
		ptr++;
	}
	if (ft_strcmp("MD5", *hash) && ft_strcmp("SHA256", *hash))
		return (1);
	return (0);
}
