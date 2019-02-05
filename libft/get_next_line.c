/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 09:51:24 by smonroe           #+#    #+#             */
/*   Updated: 2018/08/25 18:36:11 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	static char	*s[FDS];
	char		pipe[BUFF_SIZE + 1];
	char		*place;
	int			x;

	if (fd < 0 || fd >= FDS || !line || (!((!s[fd]) ? (s[fd] = ft_strnew(0))
								: (s[fd]))) || ((x = read(fd, pipe, 0)) == -1))
		return (-1);
	while ((x = read(fd, pipe, BUFF_SIZE)) > 0)
	{
		pipe[x] = '\0';
		s[fd] = ft_strjoinfr(s[fd], pipe);
	}
	if (!(s[fd][0] == '\0'))
	{
		if (!(place = ft_strchr(s[fd], '\n')))
			place = ft_strnew(0);
		else if (!(*place = '\0'))
			place = ft_strdup(place + 1);
		(*line = ft_strdup(s[fd])) ? ft_strdel(&s[fd]) : 1;
		(s[fd] = ft_strdup(place)) ? (free(place)) : 1;
		return (1);
	}
	ft_strclr(*line);
	return (x);
}
