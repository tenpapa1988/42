/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:09:54 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/15 10:24:08 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/* Didn't assume the case that dest length is shorter than src*/
// int	main(void)
// {
// 	/* test case 1 */
// 	char	dest1[] = "ABCDEFG";
// 	char	src1[] = "HIJ";
// 	unsigned int	size1 = 2;
// 	printf("The case1 sentence is %zu\n",ft_strlcpy(dest1, src1, size1));
// 	printf("The case1 sentence is %lu\n",strlcpy(dest1, src1, size1));

// 	/* test case 2 */
// 	char	dest2[] = "ABCDEFG";
// 	char	src2[] = "HIJ";
// 	unsigned int	size2 = 4;
// 	printf("The case2 sentence is %zu\n",ft_strlcpy(dest2, src2, size2));
// 	printf("The case2 sentence is %lu\n",strlcpy(dest2, src2, size2));

// 	/* test case 3 */
// 	char	dest3[] = "ABCDEFG";
// 	char	src3[] = "";
// 	unsigned int	size3 = 2;
// 	printf("The case3 sentence is %zu\n",ft_strlcpy(dest3, src3, size3));
// 	printf("The case3 sentence is %lu\n",strlcpy(dest3, src3, size3));

// 	return (0);
// }

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src || !dst)
		return (0);
	if (size > 0)
	{
		while (src[i] != '\0' && i < size -1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
