/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:35:34 by smonroe           #+#    #+#             */
/*   Updated: 2018/05/29 20:10:58 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*rev;
	int		s;
	int		i;
	long	num;

	if (n == 0)
		return (ft_strdup("0"));
	num = n;
	i = 0;
	if (!(rev = ft_strnew(ft_intlen(num))))
		return (NULL);
	s = 0;
	if (num < 0)
	{
		num *= -1;
		s = 1;
	}
	rev[i++] = (num % 10) + '0';
	while (num /= 10)
		rev[i++] = (num % 10) + '0';
	if (s)
		rev[i] = '-';
	ft_strrev(rev);
	return (rev);
}
