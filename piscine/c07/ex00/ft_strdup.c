/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:22:59 by yussaito          #+#    #+#             */
/*   Updated: 2024/01/28 18:17:02 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_strdup(char *src);

int	main(void)
{
	char	*a;
	char	*duplicate1;

	a = "apple";
	duplicate1 = ft_strdup(a);
	printf("original :%s\n", a);
	printf("Duplicate1 :%s\n", duplicate1);
	free(duplicate1);
	return (0);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*dup;
	int		i;

	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	len++;
	dup = (char *)malloc(len * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
