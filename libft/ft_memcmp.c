/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:46:28 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/20 14:33:46 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_memcmp(const void *s1, const void *s2, size_t n);

// int	main(void)
// {
// 	char	buf1[] = "ABCDEF";
// 	char	buf2[] = "ABC123";

// 	/* case1 */
// 	printf("ft_memcmp1 is %d\n", ft_memcmp(buf1, buf2, 3));
// 	printf("memcmp1 is %d\n", memcmp(buf1, buf2, 3));

// 	/* case2 */
// 	printf("ft_memcmp2 is %d\n", ft_memcmp(buf1, buf2, 4));
// 	printf("memcmp2 is %d\n", memcmp(buf1, buf2, 4));

// 	/* case3 */
// 	printf("ft_memcmp3 is %d\n", ft_memcmp(buf1, buf2, 5));
// 	printf("memcmp3 is %d\n", memcmp(buf1, buf2, 5));
// 	return (0);
// }
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(const unsigned char *)(s1 + i)
			!= *(const unsigned char *)(s2 + i))
			return (*(const unsigned char *)(s1 + i)
			- *(const unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}
