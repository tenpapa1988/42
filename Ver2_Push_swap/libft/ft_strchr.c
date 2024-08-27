/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:20:35 by yussaito          #+#    #+#             */
/*   Updated: 2024/04/22 15:33:25 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	char_c;

	char_c = (unsigned char)(c & 0xFF);
	while (*s != '\0')
	{
		if ((unsigned char)*s == char_c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && char_c == '\0')
		return ((char *)s);
	return (NULL);
}
