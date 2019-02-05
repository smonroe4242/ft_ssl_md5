/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 00:35:28 by smonroe           #+#    #+#             */
/*   Updated: 2018/11/27 15:13:06 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_H
# define SSL_H
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <math.h>
# define UMAX 4294967296
# define ALGS 2

typedef enum	e_hash
{
	md5,
	sha256
}				t_hash;

typedef struct	s_flag
{
	uint8_t		p;
	uint8_t		q;
	uint8_t		r;
	uint8_t		s;
}				t_flag;

typedef struct	s_in
{
	t_flag		flg;
	int			fd;
	char		*str;
	t_hash		hash;
	uint32_t	bytes;
}				t_in;

typedef struct	s_dt
{
	char		*key;
	void		(*f)(t_in);
}				t_dt;
/*
**		Flag Handling/File Input
*/
char			*g_optarg;
int				g_optind;
int				g_optopt;
int				ft_getopt(int argc, char **argv, char *flg);
t_flag			ft_setopt(int opt, t_flag flags, char *hash);
void			ft_runopt(char **av, int ac);
int				hash_verify(char **hash);
void			format(t_flag flg, char *hash, char *arg);
void			r_format(char *hash, char *arg, t_flag f);
void			dispatch(char *hash, t_in man);
/*
**		Utility functions
*/
uint32_t		endian_swap(uint32_t n);
uint64_t		endian_swap_64(uint64_t n);
void			usage(int n);
uint8_t			*get_stdin_seg(t_in man, uint32_t *size);
uint8_t			*get_fd_seg(t_in man, uint32_t *size);
uint8_t			*get_str_seg(t_in man, uint64_t total, uint32_t *size);
uint8_t			*get_ret(t_in man);
uint8_t			*pad(unsigned char *m, uint64_t len,
					uint16_t flip, t_hash hash);
/*
**		MD5 Functions
*/
void			digest_md5(uint32_t *l);
uint32_t		*chunk(unsigned char *m);
void			mdfive(uint32_t *k, uint32_t *s, uint32_t *l, t_in man);
uint32_t		*init_k(void);
uint32_t		*init_s(void);
void			mdfive_init(t_in man);
/*
**		SHA-256 Functions
*/
uint32_t		rrot(uint32_t n, uint32_t i);
void			digest_sha(uint32_t *h);
uint32_t		*sha_round(uint32_t *a, uint32_t *w, uint32_t *k);
uint32_t		*chunk_sha(unsigned char *m);
void			sha_256_hash(uint32_t *h, uint32_t *k, t_in man);
uint32_t		*init_h_sha(void);
uint32_t		*init_k_sha(void);
void			sha_256_init(t_in man);

#endif
