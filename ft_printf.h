/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:09:09 by sujo              #+#    #+#             */
/*   Updated: 2021/05/14 20:29:00 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define DEC "0123456789"
# define HEX "0123456789ABCDEF"

int				ft_printf(const char *str, ...);

size_t			ft_strlen(const char *s);
void			ft_putstr(const char *s);

typedef struct	s_list
{
	int			width;
	int			precision;
}				t_list;

#endif
