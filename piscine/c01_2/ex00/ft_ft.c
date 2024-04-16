/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:33:01 by yussaito          #+#    #+#             */
/*   Updated: 2024/01/18 17:26:38 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ft(int *nbr);

int	main(void)
{
	int	a;

	a = 0;
	ft_ft(&a);
	printf("%d\n",a);

	return (0);
}

void	ft_ft(int *nbr)
{
	*nbr = 42;
}
