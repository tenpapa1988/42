/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:58:17 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/15 08:52:34 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strncpy(char *dest, const char *src, size_t len);

// /* Didn't assume the case that dest length is shorter than src*/
// int	main(void)
// {
// 	/* test case 1 */
// 	char	dest1[] = "ABCDEFG";
// 	char	src1[] = "HIJ";
// 	size_t len1 = 2;
// 	printf("The case1 sentence is %s\n",ft_strncpy(dest1, src1, len1));
// 	printf("The case1 sentence is %s\n",strncpy(dest1, src1, len1));

// 	/* test case 2 */
// 	char	dest2[] = "ABCDEFG";
// 	char	src2[] = "HIJ";
// 	size_t len2 = 5;
// 	printf("The case2 sentence is %s\n",ft_strncpy(dest2, src2, len2));
// 	printf("The case2 sentence is %s\n",strncpy(dest2, src2, len2));

// 	return (0);
// }

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	while (j < len)
	{
		dest[j] = src[j];
		j++;
	}
	if (i < len)
	{
		dest[j] = '\0';
	}
	return (dest);
}
