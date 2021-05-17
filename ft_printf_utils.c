/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:31:09 by sujo              #+#    #+#             */
/*   Updated: 2021/05/17 20:59:12 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		valid_char(char c, const char *str)
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

int		get_number(char *str, int *idx)
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
