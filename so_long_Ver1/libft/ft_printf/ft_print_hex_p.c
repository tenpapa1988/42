/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:19:18 by yussaito          #+#    #+#             */
/*   Updated: 2024/05/12 15:20:27 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex_p(void *ptr, int *len)
{
	int				i;
	unsigned long	num;
	char			answer[19];

	i = 0;
	num = (unsigned long)ptr;
	if (num == 0)
	{
		write(1, "0x0", 3);
		(*len) += 3;
		return ;
	}
	while (num != 0)
	{
		answer[i++] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	write(1, "0x", 2);
	(*len) += 2;
	while (--i >= 0)
	{
		write(1, &answer[i], 1);
		(*len)++;
	}
}
