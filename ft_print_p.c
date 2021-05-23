/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 04:01:52 by sujo              #+#    #+#             */
/*   Updated: 2021/05/23 16:03:11 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		func(unsigned long nbr, int len, char *base)
{
	if (nbr == 0)
		return ;
	func(nbr / len, len, base);
	ft_putchar(base[nbr % len]);
}

void			ft_putnbr_p(unsigned long nbr, int len, char *base)
{
	func(nbr / len, len, base);
	ft_putchar(base[nbr % len]);
}

int				num_size_p(unsigned long num, int base_len)
{
	int size;

	if (num == 0)
		return (1);
	size = 0;
	while (num > 0)
	{
		num /= base_len;
		size++;
	}
	return (size);
}

void			go_print_right_p(t_format info, unsigned long num, int size)
{
	ft_put_n_char(info.width - info.precision - 2, ' ');
	ft_putstr("0x");
	ft_put_n_char(info.precision - size, '0');
	if (size)
		ft_putnbr_p(num, 16, HEX_LOW);
}

void			go_print_left_p(t_format info, unsigned long num, int size)
{
	ft_putstr("0x");
	ft_put_n_char(info.precision - size, '0');
	if (size)
		ft_putnbr_p(num, 16, HEX_LOW);
	ft_put_n_char(info.width - info.precision - 2, ' ');
}
