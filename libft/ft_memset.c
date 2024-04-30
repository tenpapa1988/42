/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:01:33 by yussaito          #+#    #+#             */
/*   Updated: 2024/04/20 12:05:39 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*a;
	int		i;

	a = (char *)b;
	i = 0;
	while (len--)
	{
		a[i] = c;
		i++;
	}
	return ((void *)a);
}
