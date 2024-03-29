/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:26:43 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/19 13:18:14 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_itoa(int n);
// static	int	itoa_length(int n);

// int	main(void)
// {
// 	char	*str;

// 	/* case1 */
// 	str = ft_itoa(1234);
// 	printf("The ft_itoa1 is %s\n", str);
// 	free(str);

// 	/* case2 */
// 	str = ft_itoa(-1234);
// 	printf("The ft_itoa2 is %s\n", str);
// 	free(str);

// 	/* case3 */
// 	str = ft_itoa(0);
// 	printf("The ft_itoa3 is %s\n", str);
// 	free(str);

// 	/* case4 */
// 	str = ft_itoa(-2147483648);
// 	printf("The ft_itoa4 is %s\n", str);
// 	free(str);
// 	return (0);
// }

static	int	itoa_length(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;

	num = n;
	len = itoa_length(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}
