/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:05:32 by sujo              #+#    #+#             */
/*   Updated: 2021/05/17 21:17:24 by sujo             ###   ########.fr       */
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
	info->precision = 0;
}

static int		get_arg(va_list ap, t_format info)
{
	int length;

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
			info.dot = 1;
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
	print_struct(info);
	return (1);
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
