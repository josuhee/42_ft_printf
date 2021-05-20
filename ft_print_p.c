/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 04:01:52 by sujo              #+#    #+#             */
/*   Updated: 2021/05/21 04:31:04 by sujo             ###   ########.fr       */
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
