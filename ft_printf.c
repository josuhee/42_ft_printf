/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:05:32 by sujo              #+#    #+#             */
/*   Updated: 2021/05/16 15:50:27 by sujo             ###   ########.fr       */
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

static int		set_format(va_list ap, char *str, int *idx)
{
	t_format	info;
	int		i_idx;
	int		end_idx;
	int		length;

	i_idx = *idx;
	init_struct(&info);
	while(valid_char(str[i_idx], TYPE) == -1)
		i_idx++;
	end_idx = i_idx;
	if (valid_char(str[i_idx], TYPE) != -1)
		return (go_print);
	if (str[i_idx] == '-' || str[i_idx] == '0')
		if (str[i_idx++] == '-')
			info.left = 1;
	return (1);
}

int		ft_printf(const char *str, ...)
{
	int		idx;
	int		cnt;
	va_list		ap;

	idx = 0;
	cnt = 0;
	va_start(ap, str);
	while(str[idx])
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
