/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:47:55 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/25 13:44:05 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// char to_upper(unsigned int i, char c)
// {
//     (void)i;
//     return (char)toupper(c);
// }

// int main(void)
// {
//     char const *s = "hello world";
//     char *result;

//     result = ft_strmapi(s, to_upper);
//     if (result == NULL) {
//         printf("Memory allocation failed\n");
//         return 1;
//     }
//     printf("Original: %s\n", s);
//     printf("Modified: %s\n", result);
//     free(result);

//     return 0;
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	length;
	char			*res;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	res = malloc(length * sizeof(char) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < length)
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
