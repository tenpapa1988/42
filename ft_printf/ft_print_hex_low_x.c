/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_low_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:22:19 by yussaito          #+#    #+#             */
/*   Updated: 2024/05/12 15:27:05 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex_low_x(unsigned int c, int *len)
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
		answer[i++] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	while (--i >= 0)
	{
		write(1, &answer[i], 1);
		(*len)++;
	}
}
