/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:06:33 by sujo              #+#    #+#             */
/*   Updated: 2021/05/20 15:35:48 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t size;

	size = 0;
	while (*s++)
		size++;
	return (size);
}

void	ft_putstr(const char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	ft_put_n_char(int cnt, char ch)
{
	int idx;

	idx = 0;
	while (idx < cnt)
	{
		write(1, &ch, 1);
		idx++;
	}
}
