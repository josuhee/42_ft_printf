/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:05:32 by sujo              #+#    #+#             */
/*   Updated: 2021/05/23 16:27:43 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (type == 'd' || type == 'i')
		length = get_type_nbr_dec(ap, info);
	if (type == 'u')
		length = get_type_u(ap, info);
	if (type == 'x')
		length = get_type_x(ap, info, HEX_LOW);
	if (type == 'X')
		length = get_type_x(ap, info, HEX_UP);
	if (type == 'p')
		length = get_type_p(ap, info);
	return (length);
}

static int		set_format(va_list ap, char *str, int *idx)
{
	t_format	info;

	init_struct(&info);
	while (valid_char(str[*idx], TYPE) == -1)
	{
		if (str[*idx] == '-')
			info.left = 1;
		if (str[*idx] == '0' && info.dot == 0)
			info.zero = 1;
		if (str[*idx] == '.')
		{
			info.dot = 1;
			info.precision = 0;
		}
		if (str[*idx] == '*')
			set_format_star(ap, &info);
		if (valid_char(str[*idx], DEC) != -1 && str[*idx] != '0')
			set_format_num(&info, str, idx);
		*idx = *idx + 1;
	}
	if (info.left == 1)
		info.zero = 0;
	return (get_arg(ap, info, str[*idx]));
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
