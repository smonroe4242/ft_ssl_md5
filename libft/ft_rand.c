/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 00:01:05 by smonroe           #+#    #+#             */
/*   Updated: 2018/04/21 08:50:08 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int		ft_rand(int max)
{
	char	num[9];
	int		n;
	int		i;
	int		r;

	i = 0;
	r = 0;
	n = open("/dev/random", O_RDONLY);
	read(n, num, 9);
	close(n);
	while (i < 9)
		r += r * 10 + (num[i++] - '0');
	r %= max;
	return (r < 0 ? -r : r);
}
