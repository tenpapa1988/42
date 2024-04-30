/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:50:25 by yussaito          #+#    #+#             */
/*   Updated: 2024/04/25 09:25:45 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*a;
	char	*b;

	a = (char *)src;
	b = (char *)dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (a < b)
	{
		while (len--)
		{
			b[len] = a[len];
		}
	}
	else
	{
		ft_memcpy(b, a, len);
	}
	return (b);
}
