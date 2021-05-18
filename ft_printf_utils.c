/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:31:09 by sujo              #+#    #+#             */
/*   Updated: 2021/05/18 23:03:53 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				valid_char(char c, const char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}

int				get_number(char *str, int *idx)
{
	int i;
	int result;

	i = *idx;
	result = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	i--;
	*idx = i;
	return (result);
}

void			put_n_char(int cnt, char ch)
{
	int idx;

	idx = 0;
	while (idx < cnt)
	{
		write(1, &ch, 1);
		idx++;
	}
}

int				num_size(long long num, int base_len)
{
	int size;

	size = 0;
	if (num < 0)
	{
		num *= -1;
		//size++;
	}
	while (num > 0)
	{
		num /= base_len;
		size++;
	}
	return (size);
}

static void		func(long long nbr)
{
	if (nbr == 0)
		return ;
	func(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

void			ft_putnbr(int n)
{
	long long nbr;

	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	func(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}
