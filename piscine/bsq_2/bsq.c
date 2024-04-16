/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:20:07 by yussaito          #+#    #+#             */
/*   Updated: 2024/01/30 20:55:46 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "mapdata.h"

#define MAX_SIZE 1000

int		read_map(const char *filename, MapData *map_data);
void	find_largest_square(char map[MAX_SIZE][MAX_SIZE], int rows \
					, int cols, char chars[3]);
void	print_map(char map[MAX_SIZE][MAX_SIZE], int rows, int cols);

int	main(int argc, char *argv[])
{
	MapData	map_data;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (read_map(argv[i], &map_data))
		{
			find_largest_square(map_data.map, map_data.rows \
						, map_data.cols, map_data.chars);
			print_map(map_data.map, map_data.rows, map_data.cols);
			if (i < argc - 1)
				write (STDOUT_FILENO, "\n", 1);
		}
		else
		{
			write(STDERR_FILENO, "map error\n", 10);
		}
		i++;
	}
	return (0);
}
