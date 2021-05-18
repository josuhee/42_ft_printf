/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:37:22 by sujo              #+#    #+#             */
/*   Updated: 2021/05/18 23:14:38 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int num;

	num = 17;
	printf("[%-5.3d]\n", num);
	printf("[%05.1d]\n", num);

	ft_printf("\n[%-5.3d]\n", num);
	ft_printf("[%05.1d]\n", num);
	//ft_printf("[%05.3d]\n", num);
	return 0;
}
