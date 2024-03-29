/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:45:18 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/14 15:55:23 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strcpy(char *dest, const char *src);

// /* Didn't assume the case that dest length is shorter than src*/
// int	main(void)
// {
// 	/* test case 1 */
// 	char	dest1[] = "ABCDEFG";
// 	char	src1[] = "HIJ";
// 	printf("The case1 sentence is %s\n",ft_strcpy(dest1, src1));
// 	printf("The case1 sentence is %s\n",strcpy(dest1, src1));

// 	/* test case 2 */
// 	char	dest2[] = "ABCDEFG";
// 	char	src2[] = "";
// 	printf("The case2 sentence is %s\n",ft_strcpy(dest2, src2));
// 	printf("The case2 sentence is %s\n",strcpy(dest2, src2));

// 	return (0);
// }

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
