/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:15:17 by yussaito          #+#    #+#             */
/*   Updated: 2024/09/07 16:03:07 by yussaito         ###   ########.fr       */
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
