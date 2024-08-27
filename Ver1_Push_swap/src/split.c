/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:15:17 by yussaito          #+#    #+#             */
/*   Updated: 2024/08/24 13:42:13 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//https://chatgpt.com/share/82f7f13a-f5ba-40f7-85d8-811d4ae2069a

// static	size_t	count_delimiters(const char *str, char delimiter)
// {
// 	size_t	count;

// 	count = 0;
// 	while(*str)
// 	{
// 		if (*str == delimiter)
// 			count++;//Only when the str is delimiter which is ' ', the count will be added
// 		str++; 
// 	}
// 	return (count);
// }

// char	**split(char *str, char delimiter)
// {
// 	size_t		count;
// 	char		**result;
// 	size_t		idx;
// 	const char	*start;
// 	const char	*end;

// 	idx = 0;
// 	start = str;
// 	count = count_delimiters(str, delimiter);
// 	result = malloc(sizeof(char *) * (count + 2));//if "42 31 1" is the argv, the count will be 2. So, we need count +2
// 	if (!result)
// 		return (NULL);
// 	while ((end = ft_strchr(start, delimiter)) != NULL)
// 	{
// 		size_t len = end - start;
// 		result[idx] = malloc(len + 1);
// 		if (!result[idx])
// 			return (NULL);
// 		strncpy(result[idx], start, len);
// 		result[idx][len] = '\0';
// 		idx++;
// 		start = end + 1;
// 	}
// 	result[idx] = ft_strdup(start);
// 	if (!result[idx])
// 		return (NULL);
// 	idx++;
// 	result[idx] = NULL;
// 	return (result);
// }

static size_t	count_delimiters(const char *str, char delimiter)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == delimiter)
			count++;
		str++;
	}
	return (count);
}

// 自作の strncpy 関数
static char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
static char	*allocate_word(const char *start, const char *end)
{
	char	*word;
	size_t	len;

	len = end - start;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strncpy(word, start, len);
	word[len] = '\0';
	return (word);
}

static int	process_words(const char *str, char delimiter, char **result)
{
	const char	*start;
	const char	*end;
	size_t		idx;

	idx = 0;
	start = str;
	while ((end = ft_strchr(start, delimiter)) != NULL)
	{
		result[idx] = allocate_word(start, end);
		if (!result[idx])
			return (1); // Allocation error
		idx++;
		start = end + 1;
	}
	result[idx] = ft_strdup(start);
	if (!result[idx])
		return (1); // Allocation error
	idx++;
	result[idx] = NULL;
	return (0);
}

char	**split(char *str, char delimiter)
{
	size_t		count;
	char		**result;

	count = count_delimiters(str, delimiter);
	result = malloc(sizeof(char *) * (count + 2)); // if "42 31 1" is the argv, the count will be 2. So, we need count + 2
	if (!result)
		return (NULL);
	if (process_words(str, delimiter, result))
	{
		// Allocation error occurred, free the allocated memory
		while (*result)
		{
			free(*result);
			result++;
		}
		return (NULL);
	}
	return (result);
}
