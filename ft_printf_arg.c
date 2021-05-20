/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:42:44 by sujo              #+#    #+#             */
/*   Updated: 2021/05/21 01:28:44 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		get_type_per(t_format info)
{
	int length;

	length = 1;
	if (info.width > 1)
		length = info.width;
	if (info.left == 0)
	{
		if (info.zero == 1)
			ft_put_n_char(length - 1, '0');
		else
			ft_put_n_char(length - 1, ' ');
		write(1, "%", 1);
	}
	else
	{
		write(1, "%", 1);
		ft_put_n_char(length - 1, ' ');
	}
	return (length);
}

int		get_type_c(va_list ap, t_format info)
{
	int		length;
	char	ch;

	ch = va_arg(ap, int);
	if (info.width > 1)
		length = info.width;
	else
		length = 1;
	if (info.left == 0)
	{
		ft_put_n_char(length - 1, ' ');
		write(1, &ch, 1);
	}
	else
	{
		write(1, &ch, 1);
		ft_put_n_char(length - 1, ' ');
	}
	return (length);
}

int		get_type_s(va_list ap, t_format info)
{
	int		tmp;
	char	*str;
	int		str_len;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	str_len = (int)ft_strlen(str);
	if (info.precision > str_len || info.precision == -1)
		info.precision = str_len;
	tmp = info.width - info.precision;
	if (tmp <= 0)
		write(1, str, info.precision);
	else if (info.left == 0)
	{
		ft_put_n_char(tmp, ' ');
		write(1, str, info.precision);
	}
	else if (info.left == 1)
	{
		write(1, str, info.precision);
		ft_put_n_char(tmp, ' ');
	}
	return (info.width > info.precision ? info.width : info.precision);
}
