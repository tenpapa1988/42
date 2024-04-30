/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:27:02 by yussaito          #+#    #+#             */
/*   Updated: 2024/04/25 15:36:45 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	cal_cpy_len(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	true_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (0);
	if (len > s_len - start)
		true_len = s_len - start;
	else
		true_len = len;
	return (true_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	true_len;
	char	*str;

	if (!s)
		return (NULL);
	true_len = cal_cpy_len(s, start, len);
	if (true_len == 0)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (true_len + 1));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < true_len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
