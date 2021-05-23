/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:34:41 by sujo              #+#    #+#             */
/*   Updated: 2021/05/23 16:07:56 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_type_nbr_dec(va_list ap, t_format info)
{
	int minus;
	int num;
	int nbr_size;

	minus = 0;
	num = va_arg(ap, int);
	if (num == 0 && info.precision == 0)
	{
		go_print_zero(info.width);
		return (info.width);
	}
	if (num < 0)
		minus = 1;
	nbr_size = num_size(num, 10);
	if (info.zero && info.precision <= -1)
		info.precision = info.width - minus;
	if (info.precision <= -1 || info.precision < nbr_size)
		info.precision = nbr_size;
	if (info.left == 0)
		go_print_right(info, num, nbr_size, minus);
	else
		go_print_left(info, num, nbr_size, minus);
	if (info.width > info.precision)
		return (info.width);
	return (info.precision + minus);
}

int		get_type_u(va_list ap, t_format info)
{
	unsigned int	num;
	int				nbr_size;

	num = va_arg(ap, unsigned int);
	nbr_size = num_size(num, 10);
	if (num == 0 && info.precision == 0)
	{
		go_print_zero(info.width);
		return (info.width);
	}
	if (info.zero && info.precision <= -1)
		info.precision = info.width;
	if (info.precision <= -1 || info.precision < nbr_size)
		info.precision = nbr_size;
	if (info.left == 0)
		go_print_right(info, num, nbr_size, 0);
	else
		go_print_left(info, num, nbr_size, 0);
	if (info.width > info.precision)
		return (info.width);
	return (info.precision);
}

int		get_type_x(va_list ap, t_format info, char *base)
{
	unsigned int	num;
	int				nbr_size;

	num = va_arg(ap, unsigned int);
	nbr_size = num_size(num, 16);
	if (num == 0 && info.precision == 0)
	{
		go_print_zero(info.width);
		return (info.width);
	}
	if (info.zero && info.precision <= -1)
		info.precision = info.width;
	if (info.precision <= -1 || info.precision < nbr_size)
		info.precision = nbr_size;
	if (info.left == 0)
		go_print_right_x(info, num, nbr_size, base);
	else
		go_print_left_x(info, num, nbr_size, base);
	if (info.width > info.precision)
		return (info.width);
	return (info.precision);
}

int		get_type_p(va_list ap, t_format info)
{
	unsigned long	num;
	int				nbr_size;

	num = (unsigned long)va_arg(ap, void *);
	nbr_size = num_size_p(num, 16);
	if (info.precision == 0 && num == 0)
		nbr_size--;
	if (info.precision < -1 || info.dot != 1 || info.precision < nbr_size)
		info.precision = nbr_size;
	if (info.width < info.precision + 2)
		info.width = info.precision + 2;
	if (info.left == 0)
		go_print_right_p(info, num, nbr_size);
	else
		go_print_left_p(info, num, nbr_size);
	return (info.width);
}
