/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:39:33 by sujo              #+#    #+#             */
/*   Updated: 2021/05/21 03:21:46 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	go_print_zero(int width)
{
	ft_put_n_char(width, ' ');
}

void	go_print_right(t_format info, long num, int size, int minus)
{
	ft_put_n_char(info.width - info.precision - minus, ' ');
	if (num < 0)
		write(1, "-", 1);
	ft_put_n_char(info.precision - size, '0');
	ft_putnbr(num, 10, DEC);
}

void	go_print_left(t_format info, long num, int size, int minus)
{
	if (num < 0)
		write(1, "-", 1);
	ft_put_n_char(info.precision - size, '0');
	ft_putnbr(num, 10, DEC);
	ft_put_n_char(info.width - info.precision - minus, ' ');
}

void	go_print_right_x(t_format info, unsigned long num, int size, char *base)
{
	ft_put_n_char(info.width - info.precision, ' ');
	ft_put_n_char(info.precision - size, '0');
	ft_putnbr(num, 16, base);
}

void	go_print_left_x(t_format info, unsigned long num, int size, char *base)
{
	ft_put_n_char(info.precision - size, '0');
	ft_putnbr(num, 16, base);
	ft_put_n_char(info.width - info.precision, ' ');
}
