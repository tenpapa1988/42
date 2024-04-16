/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:50:25 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/21 16:17:45 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memmove(void *dst, const void *src, size_t len);

// int	main(void)
// {
// 	char	buf1[] = "ABC";
// 	char	buf2[] = "1234";

// 	char	buf3[] = "ABCDEF";
// 	char	buf4[] = "123";

// 	/* case1 */
// 	printf("ft_memmove1 is %s\n", (char *)ft_memmove(buf1, buf2, 4));
// 	printf("memmove1 is %s\n", (char *)memmove(buf1, buf2, 4));

// 	/* case2 */
// 	printf("ft_memmove2 is %s\n", (char *)ft_memmove(buf3, buf4, 4));
// 	printf("memmove2 is %s\n", (char *)memmove(buf3, buf4, 4));
// 	return (0);	
// }

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*a;
	char	*b;

	a = (char *)src;
	b = (char *)dst;
	if (!dst || !src)
		return (NULL);
	if (a < b)
	{
		while (len--)
		{
			b[len] = a[len];
		}
	}
	else
	{
		ft_memcpy(b, a, len);
	}
	return (b);
}
