/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:05:34 by yussaito          #+#    #+#             */
/*   Updated: 2024/01/29 16:00:00 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max);

int	main(void)
{
	int min;
	int max;
	int *range;

	min = 5;
	max = 10;
	range = NULL;
	range = ft_range(min, max);
	if (range != NULL)
	{
		for (int i = 0; i < max - min; i++)
		{
			printf("%d ", range[i]);
		}
		printf("\n");
	} else {
		printf("NULL\n");
	}

	min = -2;
	max = 3;
	range = NULL;
	range = ft_range(min, max);
	if (range != NULL)
	{
		for (int i = 0; i < max - min; i++)
		{
			printf("%d ", range[i]);
		}
		printf("\n");
	} else {
		printf("NULL\n");
	}
	return (0);
}

int	*ft_range(int min, int max)
{
	int	size;
	int *array;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	array = (int *)malloc(size * sizeof(int));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}