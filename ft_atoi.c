/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:17:01 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/16 15:16:41 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_atoi(const char *str);

// int main(void)
// {
// 	/* case1 */
//     printf("The output1 is: %d\n", ft_atoi("  ---+--+1234ab567"));
// 	printf("The output1 is: %d\n", atoi("  ---+--+1234ab567"));

// 	/* case2 */
//     printf("The output2 is: %d\n", ft_atoi("  --+--+1234ab567"));
// 	printf("The output2 is: %d\n", atoi("  --+--+1234ab567"));

// 	/* case3 */
//     printf("The output3 is: %d\n", ft_atoi("  -+1234ab567"));
// 	printf("The output3 is: %d\n", atoi("  -+1234ab567"));

// 	/* case4 */
//     printf("The output4 is: %d\n", ft_atoi("  -1234ab567"));
// 	printf("The output4 is: %d\n", atoi("  -1234ab567"));

// 	/* case5 */
//     printf("The output5 is: %d\n", ft_atoi("  +1234ab567"));
// 	printf("The output5 is: %d\n", atoi("  +1234ab567"));

// 	/* case6 */
//     printf("The output6 is: %d\n", ft_atoi("  1234ab567"));
// 	printf("The output6 is: %d\n", atoi("  1234ab567"));
// 	return (0);
// }

int	ft_atoi(const char *str)
{
	int	i;
	int	minus_count;
	int	result;

	i = 0;
	minus_count = 0;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus_count++;
		i++;
	}
	while ('0' < str[i] && str[i] < '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (minus_count != 0)
		return (-result);
	return (result);
}
