/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:27:02 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/25 12:22:21 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_substr(char const *s, unsigned int start, size_t len);

// int	main(void)
// {
// 	char	src1[20] = "ABCDEF";
// 	char	*sub1;
// 	char	*sub2;

// 	/* case1 */
// 	sub1 = ft_substr(src1, 2, 3);
// 	printf("The ft_substr1 is %s\n",sub1);
// 	free(sub1);
// 	/* case2 */
// 	sub2 = ft_substr(src1, 5, 10);
// 	printf("The ft_substr2 is %s\n",sub2);
// 	free(sub2);
// 	return (0);	
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
