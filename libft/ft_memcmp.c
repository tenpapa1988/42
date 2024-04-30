/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:46:28 by yussaito          #+#    #+#             */
/*   Updated: 2024/04/20 12:03:20 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(const unsigned char *)(s1 + i)
			!= *(const unsigned char *)(s2 + i))
			return (*(const unsigned char *)(s1 + i)
			- *(const unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}
