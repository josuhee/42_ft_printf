/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:09:09 by sujo              #+#    #+#             */
/*   Updated: 2021/05/16 15:02:54 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define DEC "0123456789"
# define HEX "0123456789ABCDEF"
# define TYPE "cspdiuxX%"

int				ft_printf(const char *str, ...);

size_t			ft_strlen(const char *s);
void			ft_putstr(const char *s);

int			valid_char(char c, const char *str);

typedef struct			s_format
{
	int			zero;
	int			left;
	int			width;
	int			dot;
	int			precision;
}				t_format;

#endif
