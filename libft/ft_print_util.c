/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <smonroe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 06:09:55 by smonroe           #+#    #+#             */
/*   Updated: 2018/11/24 09:46:20 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_big(int64_t nbr, unsigned int base, char b)
{
	char	*s;
	char	*c;
	int		i;
	int64_t	n;

	if (nbr == 0)
		return (ft_strdup("0"));
	c = (b == 'u') ? "0123456789ABCDEF" : "0123456789abcdef";
	n = nbr;
	s = ft_strnew(64);
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

char	*ft_itoa_base_ubig(uint64_t nbr, unsigned int base, char b)
{
	char		*s;
	char		*c;
	int			i;
	uint64_t	n;

	if (nbr == 0)
		return (ft_strdup("0"));
	c = (b == 'u') ? "0123456789ABCDEF" : "0123456789abcdef";
	n = nbr;
	s = ft_strnew(64);
	i = 0;
	s[i++] = c[n % base];
	while (n /= base)
		s[i++] = c[n % base];
	ft_strrev(s);
	i = 0;
	while (!s[i])
		i++;
	c = ft_strdup(&s[i]);
	free(s);
	return (c);
}

char	*append_j(char *s, int i, int j)
{
	char	*tmp;

	tmp = ft_strnew(j);
	tmp = ft_strncpy(tmp, &s[i - j], j);
	return (tmp);
}

int		positive(t_var v)
{
	if ((v.flag == 'd' || v.flag == 'i') && v.uni.i > -1)
		return (1);
	if (v.flag == 'D' && v.uni.l > -1)
		return (1);
	return (0);
}

char	*prefix(t_var v)
{
	if (v.flag == 'x')
		return ("0x");
	else if (v.flag == 'X')
		return ("0X");
	else if ((v.flag == 'O' || v.flag == 'o') && v.uni.l)
		return ("0");
	else if (v.flag == 'b')
		return ("0b");
	else
		return ("");
}
