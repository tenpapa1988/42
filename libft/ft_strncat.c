/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:48:32 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/17 14:05:12 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strncat(char *s1, const char *s2, size_t n);

// int	main(void)
// {
// 	char	dest[20] = "SAMURAI";
// 	char	src[] = "SAMUI";

// 	char	dest2[20] = "SAMURAI";
// 	char	src2[] = "SAMUI";

// 	char	dest3[20] = "SAMURAI";
// 	char	src3[] = "SAMUI";

// 	char	dest4[20] = "SAMURAI";
// 	char	src4[] = "SAMUI";

// 	/* case1 */
// 	printf("The ft_strncat1 is %s\n", ft_strncat(dest, src, 3));
// 	printf("The strncat1 is %s\n", strncat(dest2, src2, 3));

// 	/* case2 */
// 	printf("The ft_strncat2 is %s\n", ft_strncat(dest3, src3, 7));
// 	printf("The strncat2 is %s\n", strncat(dest4, src4, 7));

// 	return (0);
// }

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	j;

	i = ft_strlen(s1);
	j = 0;
	while (j < n && s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
