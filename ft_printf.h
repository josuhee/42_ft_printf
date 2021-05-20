/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:09:09 by sujo              #+#    #+#             */
/*   Updated: 2021/05/21 04:31:14 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define DEC "0123456789"
# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"
# define TYPE "cspdiuxX%"

typedef struct	s_format
{
	int			zero;
	int			left;
	int			width;
	int			dot;
	int			precision;
}				t_format;

int				ft_printf(const char *str, ...);

size_t			ft_strlen(const char *s);
void			ft_putstr(const char *s);
void			ft_putchar(const char c);
void			ft_put_n_char(int cnt, char ch);

int				valid_char(char c, const char *str);
int				get_number(char *str, int *idx);
int				num_size(long long num, int base_len);
void			ft_putnbr(long long n, int len, char *base);

int				get_type_c(va_list ap, t_format info);
int				get_type_s(va_list ap, t_format info);
int				get_type_per(t_format info);

int				get_type_nbr_dec(va_list ap, t_format info);
int				get_type_u(va_list ap, t_format info);
int				get_type_x(va_list ap, t_format info, char *base);
int				get_type_p(va_list ap, t_format info);

void			go_print_zero(int width);
void			go_print_right(t_format info, long num, int size, int minus);
void			go_print_left(t_format info, long num, int size, int minus);
void			go_print_right_x(t_format i, unsigned long n, int s, char *b);
void			go_print_left_x(t_format i, unsigned long n, int s, char *b);

void			ft_putnbr_p(unsigned long nbr, int len, char *base);
int				num_size_p(unsigned long num, int base_len);

#endif
