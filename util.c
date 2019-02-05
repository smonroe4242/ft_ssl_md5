/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 07:15:47 by smonroe           #+#    #+#             */
/*   Updated: 2018/11/27 15:37:45 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

const t_dt		g_tab[ALGS] = {
		(t_dt){"MD5", &mdfive_init},
		(t_dt){"SHA256", &sha_256_init}
};

void		dispatch(char *hash, t_in man)
{
	int	i;

	i = -1;
	while (++i < ALGS)
		if (!ft_strcmp(g_tab[i].key, hash))
		{
			g_tab[i].f(man);
			return ;
		}
	usage(0);
}

void		usage(int n)
{
	if (n == 0)
		ft_printf("\nUsage: ./ft_ssl [hash] [-pqr] [-s 'string'] files...\n"\
				"\nMessage Digest commands:\nmd5\nsha256\n\n");
	if (n == 1)
		ft_printf("unknown option '-illegal option -- %c"\
					"\nAccepted flags: -p -q -r -s\n", g_optopt);
	if (n == 2)
		ft_printf("\nBad file read, make sure you can spell correctly\n");
	exit(0);
}

uint32_t	endian_swap(uint32_t n)
{
	return ((n >> 24) | ((n >> 8) & 0xff00)
			| ((n << 8) & 0xff0000) | (n << 24));
}

uint64_t	endian_swap_64(uint64_t n)
{
	return (((uint64_t)(endian_swap(n)) << 32) | endian_swap(n >> 32));
}

uint32_t	rrot(uint32_t n, uint32_t i)
{
	return ((n >> i | n << (32 - i)));
}
