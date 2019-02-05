/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <smonroe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 05:19:57 by smonroe           #+#    #+#             */
/*   Updated: 2018/08/24 11:07:13 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_var	init_var(void)
{
	t_var tmp;

	tmp.hash = 0;
	tmp.point = 0;
	tmp.prec = 0;
	tmp.plus = 0;
	tmp.neg = 0;
	tmp.spc = 0;
	tmp.pad = 0;
	tmp.wide[0] = 0;
	tmp.wide[1] = 0;
	tmp.wide[2] = 0;
	tmp.base = 10;
	tmp.flag = 0;
	tmp.size = 0;
	tmp.str = NULL;
	tmp.uni.ul = 0;
	return (tmp);
}

t_var	precision(t_var var, char *s, int *i)
{
	while (ft_strchr(" #.+-0123456789", s[*i]))
	{
		var.hash = (s[*i] == '#') ? s[(*i)++] : var.hash;
		if (s[*i] == '+')
			var.plus = s[(*i)++];
		if (s[*i] == '-')
			var.neg = s[(*i)++];
		if (s[*i] == ' ')
			var.spc = s[(*i)++];
		if (s[*i] == '.' || s[*i] == '0')
		{
			var.pad = (var.point == '0') ? var.prec : var.pad;
			var.point = s[(*i)++];
			var.prec = ft_atoi(&s[*i]);
			while (ft_strchr("0123456789", s[*i]))
				*i += 1;
		}
		if (ft_strchr("0123456789", s[*i]))
		{
			var.pad = ft_atoi(s + *i);
			while (ft_strchr("0123456789", s[*i]) && s[*i])
				*i += 1;
		}
	}
	return (var);
}

char	*decide(char *s, int *i, va_list ap)
{
	t_var	var;

	var = init_var();
	if (ft_strchr(" #.0123456789-+", s[*i]))
	{
		var = precision(var, s, i);
		while (ft_strchr(" #.0123456789-+", s[*i]))
			*i += 1;
	}
	if (ft_strchr("hljz", s[*i]) && s[*i])
		var.wide[0] = s[(*i)++];
	if ((s[*i] == 'h' || s[*i] == 'l') && s[*i])
		var.wide[1] = s[(*i)++];
	if (ft_strchr("sSpdDioOuUxXcC%", s[*i]) && s[*i])
		var.flag = s[*i];
	if (s[*i] == 'x' || s[*i] == 'X')
		var.base = 16;
	else if (s[*i] == 'o' || s[*i] == 'O' || s[*i] == 'b')
		var.base = (s[*i] == 'b') ? 2 : 8;
	if (var.flag == '%')
		var.uni.c = var.flag;
	return (type_field_wide(var, ap));
}

char	*parse(char *s, va_list ap)
{
	int		i;
	int		j;
	char	*buf;

	buf = ft_strnew(0);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			buf = (j) ? ft_strmrg(buf, append_j(s, i, j)) : buf;
			i++;
			buf = ft_strmrg(buf, decide(s, &i, ap));
			j = 0;
		}
		else
			j++;
	}
	buf = (j) ? ft_strmrg(buf, append_j(s, i, j)) : buf;
	return (buf);
}

int		ft_printf(char *str, ...)
{
	int		len;
	char	*buf;
	va_list	ap;

	va_start(ap, str);
	buf = parse(str, ap);
	len = ft_strlen(buf);
	ft_putstr(buf);
	free(buf);
	va_end(ap);
	return (len);
}
