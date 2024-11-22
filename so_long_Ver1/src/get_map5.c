/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:44:01 by yussaito          #+#    #+#             */
/*   Updated: 2024/11/22 11:02:52 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	dfs_map_copy(t_game *game, int x, int y, t_bool **visited)
{
	if (x < 0 || y < 0 || x >= (int)game->map.width
		|| y >= (int)game->map.height
		|| game->map_copy[y][x] == '1'
		|| visited[y][x])
	{
		return ;
	}
	visited[y][x] = TRUE;
	dfs_map_copy(game, x + 1, y, visited);
	dfs_map_copy(game, x - 1, y, visited);
	dfs_map_copy(game, x, y + 1, visited);
	dfs_map_copy(game, x, y - 1, visited);
}

void	dfs(t_game *game, int x, int y, t_bool **visited)
{
	if (x < 0 || y < 0 || x >= (int)game->map.width
		|| y >= (int)game->map.height
		|| game->map.map[y][x] == '1'
		|| visited[y][x])
	{
		return ;
	}
	visited[y][x] = TRUE;
	dfs(game, x + 1, y, visited);
	dfs(game, x - 1, y, visited);
	dfs(game, x, y + 1, visited);
	dfs(game, x, y - 1, visited);
}
