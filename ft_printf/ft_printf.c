/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:29:35 by yussaito          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/06 13:16:53 by yussaito         ###   ########.fr       */
=======
/*   Updated: 2024/05/04 11:29:37 by yussaito         ###   ########.fr       */
>>>>>>> b0bed848ced3f072c362200f5c40dacda7d80f75
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *, ...);

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

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			n;
	const char	*start;
	
	n = 0;
	va_start(ap, fmt);
	if (fmt == NULL)
		n = -1; //ここは仮置き的な感じ
	while (n >= 0 && *fmt)
	{
		
		if (*fmt == "%")

		else

		fmt = va_arg(ap, char *);
	}
	
	return (n); // 文字数を返す
}
// int	ft_printf(const char *fmt, ...)
// {
// 	va_list args;
// 	int		width;
// 	char	pad;
// 	int		num;

// 	va_start(args, fmt);

// 	while (*fmt != '\0')
// 	{
// 		//%のときだけ、ここに入る
// 		if (*fmt == '%')
// 		{
// 			fmt++;
// 			width = 0;
// 			pad = ' ';
// 			if (*fmt == '0')
// 			{
// 				pad = '0';
// 				fmt++;
// 			}
// 			while ('0' <= *fmt && *fmt <= '9')
// 			{
// 				width = width * 10 + (*fmt - '0');
// 				fmt++;
// 			}
// 			if (*fmt == 'd')
// 			{
// 				num = va_arg(args, int);
// 				print_num_flags(num, width, pad);
// 			}
// 			else
// 			{
// 				ft_putchar(*fmt);
// 			}
// 			fmt++;
// 		}
// 		//%じゃない場合には、出力する
// 	}
// 	va_end (args);
// }