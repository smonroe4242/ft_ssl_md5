/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 06:44:19 by smonroe           #+#    #+#             */
/*   Updated: 2018/08/25 18:36:48 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# define BUFF_SIZE 4096
# define FDS 4896
# define MAX3(a, b, c) ((a > b && a > c) ? c : (b > c && b > a) ? b : c)
# define MAX2(a, b) (a > b ? a : b)
# define SWAP(x, y) ((x ^= y) && (y ^= x) && (x ^= y))
# define ABS(x) ((x < 0) ? -x : x)
# define IMAX 2147483627
# define NIMAX -2147483648
# define UMAX 4294967296
# define LMAX 9223372036854775807
# define NLMAX -9223372036854775808

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef union		u_uni
{
	int8_t			c;
	int16_t			sh;
	int32_t			i;
	uint32_t		ui;
	int64_t			l;
	uint64_t		ul;
	void			*v;
	char			*s;
	int				*w;
}					t_uni;

typedef struct		s_var
{
	char			hash;
	char			point;
	int				prec;
	char			plus;
	char			neg;
	char			spc;
	int				pad;
	char			wide[3];
	unsigned int	base;
	char			flag;
	int				size;
	char			*str;
	t_uni			uni;
}					t_var;

/*
**		ft_printf
*/

char				*ft_wide(int i);
char				*ft_wider(int *s);
char				*string(t_var v);

char				*ft_itoa_base_big(int64_t nbr, unsigned int base, char b);
char				*ft_itoa_base_ubig(uint64_t nbr, unsigned int base, char b);
char				*append_j(char *s, int i, int j);
int					positive(t_var v);
char				*prefix(t_var v);

char				*printer_prec(t_var v);
char				*printer(t_var v);
t_uni				width(t_var v, va_list ap);
char				*type_field_wide(t_var c, va_list ap);
char				*type_field_norm(t_var c);

t_var				init_var(void);
t_var				precision(t_var var, char *s, int *i);
char				*decide(char *s, int *i, va_list ap);
char				*parse(char *s, va_list ap);
int					ft_printf(char *str, ...);

/*
**		libftprintf
*/

int					get_next_line(int fd, char **line);

int					ft_rand(int max);
float				ft_frand(void);

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				**ft_malloc_2d(size_t col, size_t row);

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strndup(char *s, int i);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s, char const *s2);
char				*ft_strjoinfr(char *s, char const *s2);
char				*ft_strappfr(char *s1, char *s2);
char				*ft_strmrg(char *s1, char *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_strrev(char *s);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
							size_t len);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_itoa_base(int nbr, unsigned int base, char b);
int					ft_intlen(int n);
int					ft_isprime(int n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isspace(const char c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				ft_putchar(int c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
