/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_up_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:21:45 by yussaito          #+#    #+#             */
/*   Updated: 2024/05/12 15:23:22 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex_up_x(unsigned int c, int *len)
{
	int				i;
	unsigned long	num;
	char			answer[19];

	i = 0;
	num = (unsigned long)c;
	if (num == 0)
	{
		write(1, "0", 1);
		(*len)++;
		return ;
	}
	while (num != 0)
	{
		answer[i++] = "0123456789ABCDEF"[num % 16];
		num /= 16;
	}
	while (--i >= 0)
	{
		write(1, &answer[i], 1);
		(*len)++;
	}
}
