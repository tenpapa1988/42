/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:19:12 by yussaito          #+#    #+#             */
/*   Updated: 2024/01/30 21:23:56 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mapdata.h"

#define MAX_SIZE 1000

void	print_map(char map[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
	int		i;
	int		j;
	char	newline;

	i = 0;
	j = 0;
	newline = '\n';
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			write(STDOUT_FILENO, &map[i][j], 1);
			j++;
		}
		write(STDOUT_FILENO, &newline, 1);
		i++;
	}
}
