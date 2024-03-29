/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:29:35 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/28 16:44:01 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf(const char *format, ...);

int	main(void)
{
	ft_printf("%08d\n", 123);
	ft_printf("%8d\n", 123);
	return (0);
}

void	print_num_flags(int num, int width, char pad)
{
	int	numDigits;
	int	n;

	numDigits = 0;
	n = num;
	if (num < 0)
	{
		numDigits++;
		n = -n;
	}
	else if (n == 0)
	{
		numDigits = 1;
	}
	else
	{
		while (n != 0)
		{
			numDigits++;
			n = n / 10;
		}
	}
	while (numDigits < width)
	{
		ft_putchar(pad);
		numDigits++;
	}
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num == 0 && width <= 1)
	{
		ft_putchar('0');
		return;
	}
	else if (num == 0)
	{
		return;
	}
	if (num / 10)
	{
		print_num_flags(num / 10, 0, pad);
	}
	ft_putchar(num % 10 + '0');
}
void	ft_printf(const char *format, ...)
{
	va_list args;
	int		width;
	char	pad;
	int		num;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			width = 0;
			pad = ' ';
			if (*format == '0')
			{
				pad = '0';
				format++;
			}
			while ('0' <= *format && *format <= '9')
			{
				width = width * 10 + (*format - '0');
				format++;
			}
			if (*format == 'd')
			{
				num = va_arg(args, int);
				print_num_flags(num, width, pad);
			}
			else
			{
				ft_putchar(*format);
			}
			format++;
		}
	}
	va_end (args);
}