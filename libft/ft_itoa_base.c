/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 20:43:41 by smonroe           #+#    #+#             */
/*   Updated: 2018/08/24 11:01:10 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int nbr, unsigned int base, char b)
{
	char	*s;
	char	*c;
	int		i;
	long	n;

	(void)b;
	if (nbr == 0)
		return (ft_strdup("0"));
	c = (b == 'u') ? "0123456789ABCDEF" : "0123456789abcdef";
	n = (long)nbr;
	s = ft_strnew(32);
	i = 0;
	s[i++] = c[ABS(n % base)];
	while (n /= base)
		s[i++] = c[ABS(n % base)];
	(nbr < 0 && base == 10) ? (s[i] = '-') : s[i];
	ft_strrev(s);
	i = 0;
	while (!s[i])
		i++;
	c = ft_strdup(&s[i]);
	free(s);
	return (c);
}
