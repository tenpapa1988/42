/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:43:53 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/20 08:40:35 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

// int	main(void)
// {
// 	char dst1[7] = "abcdef";
// 	char dst2[7] = "abcdef";

// 	void *result_ft;
// 	void *result_std;

// 	result_ft = ft_memccpy(dst1, "adcf", 'c', 4);
// 	result_std = memccpy(dst2, "adcf", 'c', 4);

// 	if (result_ft != NULL) {
// 		printf("ft_memccpy stopped copying at: %s\n", (char *)result_ft);
// 	} else {
// 		printf("ft_memccpy no encounter the char within the first n bytes.\n");
// 	}

// 	if (result_std != NULL) {
// 		printf("memccpy stopped copying at: %s\n", (char *)result_std);
// 	} else {
// 		printf("memccpy no encounter the char within the first n bytes.\n");
// 	}
// 	return (0);
// }
void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		if (*(unsigned char *)(src + i) == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
