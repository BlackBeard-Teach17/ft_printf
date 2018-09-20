/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 16:15:29 by kmfoloe           #+#    #+#             */
/*   Updated: 2018/08/11 15:36:19 by kmfoloe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <locale.h>
# define BIGGER(x, y) ((x > y) ? x : y)

typedef	struct		s_char
{
	wchar_t			wchar;
	wchar_t			*wstr;
	int				c;
	const char		*str;
}					t_char;

typedef struct		s_flag
{
	int				mod;
}					t_flag;

int					ft_printf(char *format, ...);
void				ft_printf_init(char **format, char *opt, int *plen,
							t_char *string);

void				get_tags(char **format, char *opt, int *plen);
void				get_flags(char **format, char *opt);
void				get_length_spec(char **format, char *opt);
void				get_precision(char **format, int *plen);
int					get_maxstrlen(t_char string, char *opt, int *plen);
int					get_maxnbrlen(long long int nbr, char *opt, int *plen);

void				print_str(char *opt, int *plen, t_char string);
void				print_nbr(char *opt, int *plen, long long int nbr);
void				print_opt(char *opt, int *plen, int max, long long int nbr);
void				print_base(int base, long long int nbr, char *opt);

void				ft_conversions(va_list ap, char *opt, int *plen,
								t_char string);
long long int		convert_nb(va_list ap, char c, char *opt);
long long int		convert_int(va_list ap, char mod, char opt);
long long int		convert_unsigned_int(va_list ap, char mod, char opt);

void				set_params(int *plen, char *opt, t_char *string);
void				set_undefined(char **format, char *opt, int *plen,
							int total);
void				set_base(char *opt, int *plen);

void				error_handle(char *opt);
void				error_duplicate(char **format, char *opt, int *plen);

int					ft_strprintlen(const char *str, char c);
int					ft_strchrlen(const char *str, char c);
int					ft_strindex(const char *str, char c);
int					ft_strlen(char const *str);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
int					nbrlen(long long int value, int base);
int					unblen(unsigned long long int value, int base);
int					ft_isupper(int c);
char				*ft_itoa_base(long long int value, int base);
char				*ft_uitoa_base(unsigned long long int value, int base);
char				*ft_strdup(const char *s1);
char				*ft_strnew(size_t size);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_bzero(void *s, size_t n);
int					ft_wstrlen(wchar_t *ws, int max);
void				ft_putwchar(wchar_t wc);
int					ft_wcharlen(wchar_t wc);
void				ft_putwstr(wchar_t *ws, int len);
void				ft_putchar(char c);
void				ft_putnstr(char const *s, int len);
void				ft_putnchar(char c, int n);
void				ft_putnbr(long long int n);
int					ft_power(int n, int pow);
char				*ft_itoa(intmax_t n);
#endif
