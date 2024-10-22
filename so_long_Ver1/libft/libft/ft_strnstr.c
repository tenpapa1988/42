/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:25:57 by yussaito          #+#    #+#             */
/*   Updated: 2024/04/26 09:26:44 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_length;
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	needle_length = ft_strlen(needle);
	if (needle_length == 0)
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		if (i + needle_length > len)
			return (NULL);
		if (ft_strncmp(&haystack[i], needle, needle_length) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
