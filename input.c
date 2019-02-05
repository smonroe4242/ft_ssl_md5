/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 00:54:16 by smonroe           #+#    #+#             */
/*   Updated: 2018/11/26 03:59:16 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

uint8_t	*get_stdin_seg(t_in man, uint32_t *size)
{
	uint8_t	*msg;
	uint8_t	buf[1];

	if (read(0, buf, 0))
		return (NULL);
	if (!(msg = (uint8_t *)ft_memalloc(man.bytes)))
		return (NULL);
	*size = 0;
	while (read(0, buf, 1))
	{
		msg[*size] = buf[0];
		if (++(*size) >= man.bytes)
			break ;
	}
	if (man.flg.p == 1)
		write(1, msg, *size);
	return (msg);
}

uint8_t	*get_fd_seg(t_in man, uint32_t *size)
{
	uint8_t	*msg;
	uint8_t	buf[1];

	if (!man.fd)
		return (get_stdin_seg(man, size));
	if (read(man.fd, buf, 0))
		return (NULL);
	if (!(msg = (uint8_t *)ft_memalloc(man.bytes)))
		return (NULL);
	*size = read(man.fd, msg, man.bytes);
	return (msg);
}

uint8_t	*get_str_seg(t_in man, uint64_t total, uint32_t *size)
{
	uint8_t	*msg;

	if (!man.str)
		return (get_fd_seg(man, size));
	if (!(msg = (uint8_t *)ft_memalloc(man.bytes)))
		return (NULL);
	*size = ft_strlen(man.str + total);
	ft_memcpy(msg, man.str + total, ((*size > man.bytes) ? man.bytes : *size));
	return (msg);
}

uint8_t	*get_ret(t_in man)
{
	static uint64_t	total;
	static uint16_t flip;
	uint8_t			*msg;
	uint32_t		size;

	if (flip == 2 || !(msg = get_str_seg(man, total, &size)))
	{
		flip = 0;
		return (NULL);
	}
	if (size < man.bytes - 8)
	{
		msg = pad(msg, total + size, flip, man.hash);
		total = 0;
		flip = 2;
	}
	else if (size < man.bytes)
	{
		total += size;
		msg[size] = 0x80;
		flip = 1;
	}
	else
		total += man.bytes;
	return (msg);
}
