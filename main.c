/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 06:35:11 by smonroe           #+#    #+#             */
/*   Updated: 2018/11/27 19:37:10 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

int		main(int ac, char **av)
{
	if (ac == 1 || hash_verify(&av[1]))
		usage(0);
	else
		ft_runopt(av, ac);
	return (0);
}

void	ft_runopt(char **av, int ac)
{
	int		opt;
	t_flag	flg;
	int		edge;

	edge = 0;
	g_optind = 2;
	ft_bzero(&flg, sizeof(flg));
	while ((opt = ft_getopt(ac, av, "pqrs:")) != -1)
	{
		if (opt == '?')
			usage(1);
		else
			flg = ft_setopt(opt, flg, av[1]);
		if (opt == 'p' || opt == 's')
			edge = 1;
	}
	if (g_optind == ac && !edge)
		format((t_flag){0, 1, 0, 0}, av[1], NULL);
	while (g_optind < ac)
		format(flg, av[1], av[g_optind++]);
}

void	format(t_flag flg, char *hash, char *arg)
{
	t_in		man;
	struct stat	sb;

	man.flg = flg;
	man.str = (man.flg.s == 1) ? arg : NULL;
	man.fd = (arg == NULL) ? 0 : open(arg, O_RDONLY);
	if (man.str == NULL && (man.fd < 0
		|| (!stat(arg, &sb) && S_ISDIR(sb.st_mode))))
	{
		ft_printf((man.fd < 0) ? "%s: %s: No such file or directory\n"
						: "%s: %s: Is a directory\n", hash, arg);
		return ;
	}
	if (man.flg.q == 0)
	{
		(man.flg.r == 0) ? r_format(hash, arg, man.flg) : 0;
		dispatch(hash, man);
		(man.flg.r == 1) ? r_format(hash, arg, man.flg) : 0;
		ft_putchar('\n');
		return ;
	}
	dispatch(hash, man);
	ft_putchar('\n');
	if (man.fd)
		close(man.fd);
}

t_flag	ft_setopt(int opt, t_flag flags, char *hash)
{
	if (opt == 'p')
	{
		flags.p = 1;
		format(flags, hash, NULL);
		flags.p = 0;
	}
	else if (opt == 'q')
		flags.q = 1;
	else if (opt == 'r')
		flags.r = 1;
	else if (opt == 's')
	{
		flags.s = 1;
		format(flags, hash, g_optarg);
		flags.s = 0;
	}
	return (flags);
}

int		ft_getopt(int ac, char **av, char *flg)
{
	static int	nxt;
	int			i;

	g_optind += (&g_optarg == &av[g_optind] ? 1 : 0);
	g_optarg = NULL;
	if (g_optind >= ac || av[g_optind][0] != '-')
		return (-1);
	i = -1;
	nxt++;
	while (++i < (int)ft_strlen(flg))
	{
		if (av[g_optind][nxt] == flg[i])
		{
			if (flg[i + 1] == ':')
				g_optarg = av[g_optind][nxt + 1] ? &av[g_optind][nxt + 1]
						: &av[g_optind + 1][0];
			if (!(av[g_optind][nxt + 1]))
				(g_optind++) ? (nxt = 0) : 0;
			g_optind += (g_optarg) ? 1 : 0;
			return (flg[i]);
		}
	}
	g_optopt = av[g_optind][nxt];
	return ('?');
}
