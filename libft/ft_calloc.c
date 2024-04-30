/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:41:38 by yussaito          #+#    #+#             */
/*   Updated: 2024/04/22 15:09:15 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	array = (void *)malloc(count * size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, (count * size));
	return (array);
}
