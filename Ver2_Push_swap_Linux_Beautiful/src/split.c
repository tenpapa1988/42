/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:15:17 by yussaito          #+#    #+#             */
/*   Updated: 2024/09/22 11:58:10 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	i;

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
	end = ft_strchr(start, delimiter);
	while (end != NULL)
	{
		result[idx] = allocate_word(start, end);
		if (!result[idx])
			return (1);
		idx++;
		start = end + 1;
		end = ft_strchr(start, delimiter);
	}
	result[idx] = ft_strdup(start);
	if (!result[idx])
		return (1);
	idx++;
	result[idx] = NULL;
	return (0);
}

char	**split(char *str, char delimiter)
{
	size_t		count;
	char		**result;

	count = count_delimiters(str, delimiter);
	result = malloc(sizeof(char *) * (count + 2));
	if (!result)
		return (NULL);
	if (process_words(str, delimiter, result))
	{
		while (*result)
		{
			free(*result);
			result++;
		}
		return (NULL);
	}
	return (result);
}
