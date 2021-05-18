/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:09:09 by sujo              #+#    #+#             */
/*   Updated: 2021/05/18 23:11:03 by sujo             ###   ########.fr       */
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

int				valid_char(char c, const char *str);
int				get_number(char *str, int *idx);
void			put_n_char(int cnt, char ch);
int				num_size(long long num, int base_len);
void			ft_putnbr(int n);

int				get_type_c(va_list ap, t_format info);
int				get_type_s(va_list ap, t_format info);
int				get_type_per(t_format info);

int				get_type_nbr_dec(va_list ap, t_format info);

#endif
