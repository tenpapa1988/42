/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:24:40 by yussaito          #+#    #+#             */
/*   Updated: 2024/02/17 13:35:36 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strjoin(char const *s1, char const *s2);

// int main(void)
// {
//     char const *s1 = "Hello";
//     char const *s2 = "World";
//     char *joinedStr = ft_strjoin(s1, s2);

//     if (joinedStr != NULL) {
//         printf("Joined string: %s\n", joinedStr);
//         free(joinedStr);
//     } else {
//         printf("Memory allocation failed\n");
//     }

//     return 0;
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	len1 = strlen(s1);
	len2 = strlen(s2);
	result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	strcpy (result, s1);
	strcat (result, s2);
	return (result);
}
