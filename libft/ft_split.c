/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:32:29 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/27 10:00:43 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c);

int	main(void)
{
	char s[] = " This is a pen. ";
	char c = ' ';
	char **dest;

	dest = ft_split(s, c);
	if (dest != NULL)
	{
		char **temp = dest;
		while (*dest != NULL)
		{
			printf("%s\n", *dest);
			free(*dest);
			dest++;
		}
		free(temp);
	}
	return (0);
}
static void	*ft_clean(char ***dest, int j)
{
	while (j-- > 0)
		free((*dest)[j]);
	free(*dest);
	return (NULL);
}

static char	**allocate_and_copy(char const *s, char c, int arr_count)
{
	char	**dest;
	int		i;
	int		j;
	int		word_len;

	if (!(dest = (char **)malloc((arr_count + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < arr_count)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		word_len = 0;
		while (s[i + word_len] != c && s[i + word_len] != '\0')
			word_len++;
		if (!(dest[j] = (char *)malloc((word_len + 1) * sizeof(char))))
			return (ft_clean(&dest, j));
		ft_strlcpy(dest[j++], s + i, word_len + 1);
		i += word_len;
	}
	dest[j] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		arr_count;

	if (!s)
		return (NULL);
	i = 0;
	arr_count = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
		arr_count++;
		i++;
	}
	return (allocate_and_copy(s, c, arr_count));
}
