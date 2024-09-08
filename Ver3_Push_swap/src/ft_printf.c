/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 08:49:26 by yussaito          #+#    #+#             */
/*   Updated: 2024/09/08 08:50:24 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			len;
	int			i;

	len = 0;
	i = 0;
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		write(1, &fmt[i], 1);
		len++;
		i++;
	}
	va_end(ap);
	return (len);
}
