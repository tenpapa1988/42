/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:20:35 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/16 17:47:42 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strchr(const char *s, int c);

// int	main(void)
// {
// 	char	s[] = "ABC";
// 	char	t[] = "A1C";	
// 	int		c = 'C';
// 	int		d = '\0';
// 	int		e = 'E';
// 	int		f = '1';

// 	/* case1 */
// 	printf("The pointer1 is %s\n", ft_strchr(s, c));
// 	printf("The pointer1 is %s\n", strchr(s, c));

// 	/* case2 */
// 	printf("The pointer2 is %s\n", ft_strchr(s, d));
// 	printf("The pointer2 is %s\n", strchr(s, d));

// 	/* case3 */
// 	printf("The pointer3 is %s\n", ft_strchr(s, e));
// 	printf("The pointer3 is %s\n", strchr(s, e));

// 	/* case4 */
// 	printf("The pointer4 is %s\n", ft_strchr(t, f));
// 	printf("The pointer4 is %s\n", strchr(t, f));
// 	return (0);
// }

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0')
		return ((char *)s);
	return (NULL);
}
