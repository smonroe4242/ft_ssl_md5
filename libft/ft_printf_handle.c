/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 18:40:28 by smonroe           #+#    #+#             */
/*   Updated: 2018/08/24 21:08:39 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*printer_prec(t_var v)
{
	if (!positive(v) && v.base == 10 && v.prec >= (int)ft_strlen(v.str))
		v.str[0] = '0';
	while ((int)ft_strlen(v.str) < v.prec)
		v.str = ft_strappfr("0", v.str);
	if (!positive(v) && v.base == 10 && v.str[0] != '-')
		v.str = ft_strappfr("-", v.str);
	return (v.str);
}

char	*printer(t_var v)
{
	if (v.flag == 's')
		return (string(v));
	if (v.prec)
		v.str = printer_prec(v);
	if (v.plus && positive(v))
	{
		if (v.point == '0')
			v.str[0] = '+';
		else
			v.str = ft_strappfr("+", v.str);
	}
	if (v.hash)
		v.str = ft_strappfr(prefix(v), v.str);
	if (v.spc && !v.plus && v.str[0] != '-')
		v.str = ft_strappfr(" ", v.str);
	if (v.pad)
	{
		if (v.neg)
			while ((int)ft_strlen(v.str) < v.pad)
				v.str = ft_strjoinfr(v.str, " ");
		if (!v.neg)
			while ((int)ft_strlen(v.str) < v.pad)
				v.str = ft_strappfr(" ", v.str);
	}
	return (v.str);
}

t_uni	width(t_var v, va_list ap)
{
	if (v.wide[1] == 'h')
		v.uni.c = va_arg(ap, int);
	else if (v.wide[0] == 'h')
		v.uni.sh = va_arg(ap, int);
	else if (ft_strchr("ljz", v.wide[0]) && ft_strchr("id", v.flag))
		v.uni.l = va_arg(ap, int64_t);
	else if (ft_strchr("ljz", v.wide[0]) && ft_strchr("uUxXoOb", v.flag))
		v.uni.ul = va_arg(ap, uint64_t);
	else if (ft_strchr("idcC", v.flag))
		v.uni.i = va_arg(ap, int32_t);
	else if (ft_strchr("uxXob", v.flag))
		v.uni.ui = va_arg(ap, uint32_t);
	else if (v.flag == 'D')
		v.uni.l = va_arg(ap, int64_t);
	else if (v.flag == 'U' || v.flag == 'O')
		v.uni.ul = va_arg(ap, uint64_t);
	else if (v.flag == 's')
		v.uni.s = va_arg(ap, char *);
	else if (v.flag == 'S')
		v.uni.w = va_arg(ap, int *);
	else if (v.flag == 'p')
		v.uni.v = va_arg(ap, void *);
	else if (v.flag == '%')
		v.uni.c = '%';
	return (v.uni);
}

char	*type_field_wide(t_var v, va_list ap)
{
	v.uni = width(v, ap);
	if (v.wide[0])
	{
		if (ft_strchr("XuUoOb", v.flag))
			v.str = ft_itoa_base_ubig(v.uni.ul, v.base, 'u');
		else if (ft_strchr("idD", v.flag))
			v.str = ft_itoa_base_big(v.uni.l, v.base, 'l');
		else if (v.flag == 'x')
			v.str = ft_itoa_base_ubig(v.uni.ul, v.base, 'l');
		else if (v.flag == 's')
			v.str = ft_wider(v.uni.w);
		else
			v.str = ft_strdup("WATBOI");
		return (printer(v));
	}
	if (v.flag == 'C')
		v.str = ft_wide(v.uni.i);
	else if (v.flag == 'S')
		v.str = ft_wider(v.uni.w);
	else
		return (type_field_norm(v));
	return (printer(v));
}

char	*type_field_norm(t_var v)
{
	if (ft_strchr("xobu", v.flag))
		v.str = ft_itoa_base_ubig(v.uni.ui, v.base, 'l');
	else if (v.flag == 'X')
		v.str = ft_itoa_base_ubig(v.uni.ui, v.base, 'u');
	else if (v.flag == 'i' || v.flag == 'd')
		v.str = ft_itoa_base(v.uni.i, v.base, 'u');
	else if (v.flag == 'U' || v.flag == 'O')
		v.str = ft_itoa_base_ubig(v.uni.ul, v.base, 'l');
	else if (v.flag == 'D')
		v.str = ft_itoa_base_big(v.uni.l, v.base, 'l');
	else if (v.flag == 'p')
		v.str = ft_strappfr("0x", ft_itoa_base_ubig(v.uni.ul, 16, 'l'));
	else if (v.flag == 'c' || v.flag == '%')
	{
		v.str = ft_strnew(2);
		v.str[0] = (v.flag == '%') ? '%' : v.uni.c;
		if (!v.str[0])
		{
			write(1, v.str, 1);
			return (v.str);
		}
	}
	else if (v.flag == 's')
		v.str = ft_strdup((v.uni.s) ? v.uni.s : "(null)");
	return (printer(v));
}
