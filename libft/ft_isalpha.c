/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:50:58 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/19 10:18:25 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_isalpha(int c);

// int	main(void)
// {
// 	/* case1 */
// 	printf("The return1 is %d\n", ft_isalpha('a'));
// 	printf("The return1 is %d\n", isalpha('a'));

// 	/* case2 */
// 	printf("The return2 is %d\n", ft_isalpha('2'));
// 	printf("The return2 is %d\n", isalpha('2'));
// 	return (0);
// }

int	ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		return (1);
	return (0);
}
