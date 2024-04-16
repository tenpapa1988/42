/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:18:09 by yussaito          #+#    #+#             */
/*   Updated: 2024/01/30 21:30:56 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapdata.h"

#define MAX_SIZE 1000

int	read_map(const char *filename, MapData *map_data)
{
	FILE	*file;
	char	info_line[MAX_SIZE];
	int		row;

	file = fopen(filename, "r");
	if (!file)
		return (0);
	if (!fgets(info_line, MAX_SIZE, file))
		return (0);
	if (sscanf(info_line, "%d%c%c%c", &map_data->rows, &map_data->chars[0], \
		&map_data->chars[1], &map_data->chars[2]) != 4)
		return (0);
	row = 0;
	while (fgets(map_data->map[row], MAX_SIZE, file) && row < map_data->rows)
	{
		if (map_data->map[row][strlen(map_data->map[row]) - 1] == '\n')
			map_data->map[row][strlen(map_data->map[row]) - 1] = '\0';
		if (strlen(map_data->map[row]) != (size_t) map_data->cols)
			return (0);
		row++;
	}
	map_data->cols = strlen(map_data->map[0]);
	return (1);
}
