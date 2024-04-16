/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:12:54 by yussaito          #+#    #+#             */
/*   Updated: 2024/01/18 14:42:02 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void);

int	main(void)
{
	ft_print_alphabet();

	return (0);
}

void	ft_print_alphabet(void)
{
	char	i;

	i = 'a';
	while(i <= 'z')
	{
		write(1, &i, 1);
		i++;
	}
}
