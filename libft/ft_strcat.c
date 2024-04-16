/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:21:03 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/17 13:29:09 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strcat(char *s1, const char *s2);

// int	main(void)
// {
// 	char	s1[] = "Hello";
// 	char	s2[] = "World";
// 	printf("%s\n", ft_strcat(s1, s2));
// 	return (0);
// }

char	*ft_strcat(char *s1, const char *s2)
{
	ft_strcpy(&s1[ft_strlen(s1)], s2);
	return (s1);
}
