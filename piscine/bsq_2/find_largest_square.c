/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_largest_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:18:26 by yussaito          #+#    #+#             */
/*   Updated: 2024/01/30 21:58:01 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "mapdata.h"
#define MAX_SIZE 1000

typedef struct Map_info {
	char	map[MAX_SIZE][MAX_SIZE];
	int		rows;
	int		cols;
	char	empty_char;
}	t_MapInfo;

typedef struct Dp_data {
	int	dp[MAX_SIZE][MAX_SIZE];
	int	max_info[3];
}	t_DPData;

int	min(int a, int b, int c)
{
	int	minimum;

	minimum = a;
	if (b < minimum)
	{
		minimum = b;
	}
	if (c < minimum)
	{
		minimum = c;
	}
	return (minimum);
}

void	update_dp(t_DPData *dp_data, t_MapInfo *map_info)
{
	int	i;
	int	j;

	i = 0;
	dp_data->max_info[0] = 0;
	dp_data->max_info[1] = 0;
	dp_data->max_info[2] = 0;
	while (i < map_info->rows)
	{
		j = 0;
		while (j < map_info->cols)
		{
			dp_data->dp[i][j] = map_info->map[i][j] == map_info->empty_char ? 1 : 0;
			if (i && j && dp_data->dp[i][j]) 
				dp_data->dp[i][j] = min(dp_data->dp[i-1][j-1]
				, dp_data->dp[i][j-1], dp_data->dp[i-1][j]) + 1;
			if (dp_data->dp[i][j] > dp_data->max_info[0])
			{
				dp_data->max_info[0] = dp_data->dp[i][j]; 
				dp_data->max_info[1] = i; 
				dp_data->max_info[2] = j;
			}
			j++;
		}
		i++;
	}
}

void	mark_largest_square(t_MapInfo *map_info \
		, t_DPData *dp_data, char full_char)
{
	int	i;
	int	j;

	i = dp_data->max_info[1] - dp_data->max_info[0] + 1;
	while (i <= dp_data->max_info[1])
	{
		j = dp_data->max_info[2] - dp_data->max_info[0] + 1;
		while (j <= dp_data->max_info[2])
		{
			map_info->map[i][j] = full_char;
			j++;
		}
		i++;
	}
}

void	find_largest_square(char map[MAX_SIZE][MAX_SIZE] \
							, int rows, int cols, char chars[3])
{
	t_DPData	dp_data;
	t_MapInfo	map_info;
	memset(map_info.map, 0, sizeof(map_info.map));
	map_info.rows = rows;
	map_info.cols = cols;
	map_info.empty_char = chars[0];
	update_dp(&dp_data, &map_info);
	mark_largest_square(&map_info, &dp_data, chars[2]);
}
