/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:43:20 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/17 15:28:38 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlcat(char *dst, const char *src, size_t size);

// int	main(void)
// {
// 	char	dest[] = "SAMURAI";
// 	char	src[] = "SAMUI";

// 	char	dest3[] = "SAMURAI";
// 	char	src3[] = "SAMUI";

// 	/* case1 */
// 	printf("The ft_strlcat1 is %zu\n", ft_strlcat(dest, src, 15));

// 	/* case2 */
// 	printf("The ft_strncat2 is %zu\n", ft_strlcat(dest3, src3, 5));
// 	return (0);
// }

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	j = dst_len;
	i = 0;
	if (dst_len < size - 1 && size > 0)
	{
		while (src[i] != '\0' && dst_len + i < size - 1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	if (dst_len >= size)
		dst_len = size;
	return (dst_len + src_len);
}
