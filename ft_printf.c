/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:05:32 by sujo              #+#    #+#             */
/*   Updated: 2021/05/18 23:11:46 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void		init_struct(t_format *info)
{
	info->zero = 0;
	info->left = 0;
	info->width = 0;
	info->dot = 0;
	info->precision = -1;
}

static int		get_arg(va_list ap, t_format info, char type)
{
	int length;

	length = 0;
	if (type == 'c')
		length = get_type_c(ap, info);
	if (type == 's')
		length = get_type_s(ap, info);
	if (type == '%')
		length = get_type_per(info);
	if (type == 'd')
		length = get_type_nbr_dec(ap, info);
	/*
	if (type == 'p')
	if (type == 'd')
	if (type == 'i')
	if (type == 'u')
	if (type == 'x')
	if (type == 'X')
	*/
	return (length);
}

/*제출할 땐 삭제하기*/
void			print_struct(t_format info)
{
	printf("\n=======[struct info]========\n");
	printf("zero\t: %d\n", info.zero);
	printf("left\t: %d\n", info.left);
	printf("width\t: %d\n", info.width);
	printf("dot\t: %d\n", info.dot);
	printf("prec\t: %d\n", info.precision);
	printf("============================\n");
}

static int		set_format(va_list ap, char *str, int *idx)
{
	t_format	info;
	int			i_idx;
	int			num;

	i_idx = *idx;
	init_struct(&info);
	while (valid_char(str[i_idx], TYPE) == -1)
	{
		if (str[i_idx] == '-')
			info.left = 1;
		if (str[i_idx] == '0' && info.dot == 0)
			info.zero = 1;
		if (str[i_idx] == '.')
		{
			info.dot = 1;
			info.precision = 0;
		}
		if (str[i_idx] == '*')
		{
			if (info.dot == 0)
				info.width = va_arg(ap, int);
			else
				info.precision = va_arg(ap, int);
		}
		if (valid_char(str[i_idx], DEC) != -1 && str[i_idx] != '0')
		{
			num = get_number(str, &i_idx);
			if (info.dot == 0)
				info.width = num;
			else
				info.precision = num;
		}
		i_idx++;
	}
	*idx = i_idx;
	//print_struct(info);
	return (get_arg(ap, info, str[i_idx]));
}

int				ft_printf(const char *str, ...)
{
	int			idx;
	int			cnt;
	va_list		ap;

	idx = 0;
	cnt = 0;
	va_start(ap, str);
	while (str[idx])
	{
		if (str[idx] == '%')
		{
			idx++;
			cnt += set_format(ap, (char *)str, &idx);
		}
		else
		{
			write(1, &str[idx], 1);
			cnt++;
		}
		idx++;
	}
	va_end(ap);
	return (cnt);
}
