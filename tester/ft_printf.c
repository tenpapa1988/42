/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:29:35 by yussaito          #+#    #+#             */
/*   Updated: 2024/05/12 14:51:15 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_print_int(int c, int *len)
{
	char	*tmp;
	int		i;

	tmp = ft_itoa(c);
	i = 0;
	while(tmp[i] != '\0')
	{
		write(1, &tmp[i], 1);
		i++;
		(*len)++;
	}
	free(tmp);
}

static	void	ft_print_deci(unsigned int c, int *len)
{
	char			*tmp;
	int				i;

	tmp = ft_utoa(c);
	i = 0;
	while(tmp[i] != '\0')
	{
		write(1, &tmp[i], 1);
		i++;
		(*len)++;
	}
	free(tmp);
}

//負の値を取った場合にどうすればよいのか？は質問する
static	void	ft_print_hex_x(unsigned int c, int *len)
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

static	void	ft_print_hex_X(unsigned int c, int *len)
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

static	void	ft_print_char(int i, int *len)
{
	char	c;

	c = (char)i;
	write(1, &c, 1);
	(*len)++;
}

static	void	ft_print_str(char *c, int *len)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		write(1,&c[i],1);
		(*len)++;
		i++;
	}
}

static	void	ft_print_hex_p(void *ptr, int *len)
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
	write(1,"0x",2);
	(*len) += 2;
	while (--i >= 0)
	{
		write(1, &answer[i], 1);
		(*len)++;
	}
}


static	void	ft_check(const char *fmt, int i, va_list *ap, int *len)
{
	if (fmt[i] == 'i' || fmt[i] == 'd')
		ft_print_int(va_arg(*ap, int), len);
	else if (fmt[i] == 'u')
		ft_print_deci(va_arg(*ap, unsigned int), len);
	else if (fmt[i] == 'x')
		ft_print_hex_x(va_arg(*ap, unsigned int), len);
	else if (fmt[i] == 'X')
		ft_print_hex_X(va_arg(*ap, unsigned int), len);
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
