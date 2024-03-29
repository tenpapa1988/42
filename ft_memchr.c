/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:12:13 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/20 08:41:59 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memchr(const void *s, int c, size_t n);

// int	main(void)
// {
// 	char src1[7] = "abcdef";
// 	char src2[7] = "abcdef";

// 	void *result_ft;
// 	void *result_std;

// 	result_ft = ft_memchr(src1, 'c', 4);
// 	result_std = memchr(src2, 'c', 4);

// 	if (result_ft != NULL) {
// 		printf("ft_memchr stopped copying at: %s\n", (char *)result_ft);
// 	} else {
// 		printf("ft_memchr no encounter the char within the first n bytes.\n");
// 	}

// 	if (result_std != NULL) {
// 		printf("memchr stopped copying at: %s\n", (char *)result_std);
// 	} else {
// 		printf("memchr no encounter the char within the first n bytes.\n");
// 	}
// 	return (0);
// }
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (*(const unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)((unsigned char *)s + i));
		i++;
	}
	return (NULL);
}
