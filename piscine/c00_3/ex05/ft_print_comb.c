/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:42:24 by yussaito          #+#    #+#             */
/*   Updated: 2024/01/18 15:56:58 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);

int	main(void)
{
	ft_print_comb();

	return (0);
}

void ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = i + 1;
	k = j + 1;
	while (i <= 7)
	{
		j = i + 1;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				write("%d%d%d\n", i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
