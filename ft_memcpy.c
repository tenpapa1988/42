/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:34:28 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/21 16:16:32 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memcpy(void *dst, const void *src, size_t n);

// int	main(void)
// {
// 	char	buf1[] = "ABCDEF";
// 	char	buf2[] = "123";

// 	char	buf3[] = "ABCDEF";
// 	char	buf4[] = "123";

// 	/* case1 */
// 	printf("ft_memcpy1 is %s\n", (char *)ft_memcpy(buf1, buf2, 3));
// 	printf("memcpy1 is %s\n", (char *)memcpy(buf1, buf2, 3));

// 	/* case2 */
// 	printf("ft_memcpy2 is %s\n", (char *)ft_memcpy(buf3, buf4, 4));
// 	printf("memcpy2 is %s\n", (char *)memcpy(buf3, buf4, 4));
// 	return (0);
// }

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}
