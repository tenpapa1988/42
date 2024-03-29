/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:49:15 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/17 12:33:41 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strdup(const char *s1);

// int	main(void)
// {
// 	char	str[] = "ABCDE";

// 	printf("The original content is %s\n", str);
// 	printf("The ft_strdup content is %s\n", ft_strdup(str));
// 	printf("The strdup content is %s\n", strdup(str));
// 	free(ft_strdup(str));
// 	free(strdup(str));
// }

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	dest = (char *)malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
