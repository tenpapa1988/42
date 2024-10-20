/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:23:42 by yussaito          #+#    #+#             */
/*   Updated: 2024/05/12 15:24:05 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_int(int c, int *len)
{
	char	*tmp;
	int		i;

	tmp = ft_itoa(c);
	i = 0;
	while (tmp[i] != '\0')
	{
		write(1, &tmp[i], 1);
		i++;
		(*len)++;
	}
	free(tmp);
}
