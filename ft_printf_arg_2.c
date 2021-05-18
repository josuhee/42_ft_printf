/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:34:41 by sujo              #+#    #+#             */
/*   Updated: 2021/05/18 23:12:11 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_type_nbr_dec(va_list ap, t_format info)
{
	int minus;
	int num;
	int length;
	int nbr_size;

	minus = 0;
	if (num < 0)
		minus = 1;
	num = va_arg(ap, int);
	nbr_size = num_size(num, 10);
	if (info.precision == -1)
		info.precision = info.width;
	if (info.precision < nbr_size)
		info.precision = nbr_size;
	if (info.left == 0)
	{
		put_n_char(info.width - info.precision - minus, ' ');
		if (num < 0)
			write(1, "-", 1);
		put_n_char(info.precision - nbr_size, '0');
		ft_putnbr(num);
	}
	else
	{
		if (num < 0)
			write(1, "-", 1);
		put_n_char(info.precision - nbr_size, '0');
		ft_putnbr(num);
		put_n_char(info.width - info.precision - minus, ' ');
	}
	return (0);
}
