/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:43:22 by yussaito          #+#    #+#             */
/*   Updated: 2024/04/25 09:40:46 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	char_c;
	size_t			n;

	char_c = (unsigned char)(c & 0xFF);
	n = ft_strlen(s);
	if (char_c == 0)
		return ((char *)&s[n]);
	if (n == 0)
		return (NULL);
	n--;
	while (n > 0)
	{
		if ((unsigned char)s[n] == char_c)
			return ((char *)&s[n]);
		n--;
	}
	if ((unsigned char)s[n] == char_c)
		return ((char *)&s[n]);
	return (NULL);
}
