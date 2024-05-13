/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:29:35 by yussaito          #+#    #+#             */
/*   Updated: 2024/05/12 15:24:29 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check(const char *fmt, int i, va_list *ap, int *len)
{
	if (fmt[i] == 'i' || fmt[i] == 'd')
		ft_print_int(va_arg(*ap, int), len);
	else if (fmt[i] == 'u')
		ft_print_deci(va_arg(*ap, unsigned int), len);
	else if (fmt[i] == 'x')
		ft_print_hex_low_x(va_arg(*ap, unsigned int), len);
	else if (fmt[i] == 'X')
		ft_print_hex_up_x(va_arg(*ap, unsigned int), len);
	else if (fmt[i] == 'c')
		ft_print_char(va_arg(*ap, int), len);
	else if (fmt[i] == 's')
		ft_print_str(va_arg(*ap, char *), len);
	else if (fmt[i] == 'p')
		ft_print_hex_p(va_arg(*ap, void *), len);
	else if (fmt[i] == '%')
	{
		write(1, "%", 1);
		(*len)++;
	}
	return ;
}

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
		if (fmt[i] == '%')
		{
			i++;
			ft_check(fmt, i, &ap, &len);
		}
		else
		{
			write(1, &fmt[i], 1);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
