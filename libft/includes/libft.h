/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzo <lorenzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 02:07:00 by lde-medi          #+#    #+#             */
/*   Updated: 2025/11/20 00:19:02 by lorenzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define GNL_FLUSH -42
# define GNL_NOFLUSH 0

# define PRINTF_BUF 64
# define LC_HX "0123456789abcdef"
# define UC_HX "0123456789ABCDEF"

typedef struct s_vector2double
{
	double	x;
	double	y;
}	t_v2d;

typedef struct s_vector2int
{
	int	x;
	int	y;
}	t_v2i;

typedef struct s_printf_data
{
	char	*buf;
	size_t	buf_sz;
	int		buf_len;
	int		buf_i;
}	t_pf_data;

typedef struct s_join_n_str_data
{
	char	*out;
	char	*cur_s;
	char	*tmp;
	int		out_l;
	int		cr_len;
}	t_jns_d;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* gnl/ */
char			*ft_get_next_line(int fd, int flush);
char			*gnl_init_store(int fd, char **store);
char			*gnl_extract_line(char **store);
char			*gnl_add_to_store(char **store, char *buffer);

/* char/ */
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isspace(int c);
int				ft_tolower(int c);

/* memory/ */
int				ft_memcmp(const void *p1, const void *p2, size_t num);
void			ft_bzero(void *s, size_t n);
void			ft_multifree(int n, ...);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memset(void *str, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_calloc(size_t n, size_t size);

/* io/ */
int				print_string(int fd, const char *str);
char			*ft_sprintf(const char *fmt, ...);
int				ft_dprintf(int fd, const char *fmt, ...);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int nb, int fd);
int				ft_printf(const char *fmt, ...);
void			ft_putendl_fd(char *s, int fd);
int				init_pf_buf(t_pf_data	*data, char	*str);
int				w_ptr_to_b(t_pf_data *data, uintptr_t nbr, char	*base);
int				w_nb_to_b(t_pf_data	*data, int nb);
int				w_uint_to_b(t_pf_data	*data, unsigned int nb);
int				r_w_str_to_b(t_pf_data	*data, char	*str, int size);
int				w_hexa_to_b(t_pf_data	*data, unsigned int nbr, char	*base);
int				w_ch_to_b(t_pf_data	*data, int c);
int				w_str_to_b(t_pf_data	*data, char	*str);
void			ft_putchar_fd(char c, int fd);

/* conv/ */
int				ft_atoi(const char *str);
char			*ft_itoa(int n);

/* list/ */
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst,
					void *(*f)(void *), void (*del)(void *));
int				ft_lstsize(t_list *lst);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));

/* math/ */
int				ft_sqrt(int nb);
int				ft_clamp_i(int num, int min, int max);
float			ft_clamp_f(float num, float min, float max);
double			ft_clamp_d(double num, double min, double max);

/* math/vector_utils */
t_v2d			ft_v2i_to_v2d(t_v2i v_int);
t_v2i			ft_v2d_to_v2i(t_v2d v_double);

/* math/v2i */
t_v2i			ft_set_v2i(int x, int y);
t_v2i			ft_sum_v2i(t_v2i v1, t_v2i v2);
t_v2i			ft_subtr_v2i(t_v2i v1, t_v2i v2);
t_v2i			ft_multiply_v2i(t_v2i vec, int scalar);
double			ft_length_v2i(t_v2i	vec);
double			ft_distance_v2i(t_v2i v1, t_v2i v2);

/* math/v2d */
t_v2d			ft_set_v2d(double x, double y);
t_v2d			ft_sum_v2d(t_v2d v1, t_v2d v2);
t_v2d			ft_subtr_v2d(t_v2d v1, t_v2d v2);
t_v2d			ft_multiply_v2d(t_v2d vec, double scalar);
double			ft_length_v2d(t_v2d	vec);
double			ft_distance_sq_v2d(t_v2d v1, t_v2d v2);

/* misc/ */
void			*ft_ternop(bool	cond, void	*case_true, void *case_false);
int				ft_ternop_int(bool	cond, int case_true, int case_false);
int				ft_arr_len(char	**arr);

/* string/ */
char			*ft_strnstr(char *big, char *little, size_t len);
size_t			ft_strlcpy(char *dest, char *src, size_t size);
int				ft_strlen(const char *str);
char			*ft_strchr(const char *s, int c);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(const char *s1, const char *s2);
int				ft_strchcount(const char *str, const char c);
char			**ft_split(char const *s, char c);
char			*ft_strrchr(const char *s, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_join_n_str(char *s1, ...);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char			*ft_strdup(const char *src);
char			*ft_strtok(char	*str, const char	*sep);
int				ft_strcmp(const char *s1, const char *s2);

int				ft_vdprintf(int fd, const char *fmt, va_list *ap);
int				convert(t_pf_data	*data, char c, va_list *args);

#endif