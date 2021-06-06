/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:21:59 by sujo              #+#    #+#             */
/*   Updated: 2021/05/23 16:25:29 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_format_star(va_list ap, t_format *info)
{
	if (info->dot == 0)
	{
		info->width = va_arg(ap, int);
		if (info->width < 0)
		{
			info->width *= -1;
			info->left = 1;
			info->zero = 0;
		}
		if (info->width == 0)
			info->zero = 0;
	}
	else
	{
		info->precision = va_arg(ap, int);
		if (info->precision < 0)
			info->precision = -2;
	}
}

void	set_format_num(t_format *info, char *str, int *idx)
{
	int num;

	num = get_number(str, idx);
	if (info->dot == 0)
		info->width = num;
	else
		info->precision = num;
}
