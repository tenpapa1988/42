/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:44:01 by yussaito          #+#    #+#             */
/*   Updated: 2024/11/20 10:14:47 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//Cに到達可能か？をチェックする
t_bool	check_reachable(t_game *game, t_bool **visited, char target)
{
	size_t	x;
	size_t	y;
	t_bool	reachable;

	reachable = TRUE;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.map[y][x] == target && !visited[y][x])
				reachable = FALSE;//マップの各マスがC＆visitedがFALSEだったら、即座にリーチできないと処理する
			x++;
		}
		y++;
	}
	return (reachable);
}

//マップをコピする関数
char	**copy_map(t_game *game)
{
	char	**map_copy;
	size_t	y;

	map_copy = (char **)malloc(sizeof(char *) * game->map.height);
	if (!map_copy)
		free_and_exit("Failed to allocate memory for map copy", game, NULL, 0);
	y = 0;
	while (y < game->map.height)
	{
		map_copy[y] = ft_strdup(game->map.map[y]);
		if (!map_copy[y])
		{
			while (y > 0)
				free(map_copy[--y]);
			free(map_copy);
			free_and_exit("Failed to allocate memory for map row",
				game, NULL, 0);
		}
		y++;
	}
	return (map_copy);
}

static t_bool	check_collectibles_reachable(t_game *game, char **map_copy)
{
	t_bool	**visited;
	t_bool	reachable;

	visited = allocate_visited(game);//訪問済みか？をチェックするための
	if (!visited)
		free_and_exit("Failed to allocate memory for collectibles check",
			game, map_copy, game->map.height);
	dfs(game, game->player.x, game->player.y, visited);//Pを起点として探索
	reachable = check_reachable(game, visited, 'C');//Cが訪問可能か？をチェック
	free_visited(visited, game->map.height);//visitedをfreeする
	return (reachable);
}
//Eに辿り着くのか？を検証する関数。visitedはオリジナルマップを利用
//check_collectibles_reachable関数と同じでもよかったはずなんですが、一度freeしてるにも関わらず、なぜかうまく機能しなかったので、こうした
//機能しないとは、上書きが発生してしまって、正確なマップが取得できなかったという意味
static t_bool	check_exit_reachable(t_game *game)
{
	t_bool	**visited;
	t_bool	reachable;

	visited = allocate_visited(game);
	if (!visited)
		free_and_exit("Failed to allocate memory for exit check",
			game, game->map.map, game->map.height);
	dfs(game, game->player.x, game->player.y, visited);
	reachable = check_reachable(game, visited, 'E');
	free_visited(visited, game->map.height);
	return (reachable);
}
//まずEを1に置き換えてしまって、Eに塞がれていないか？をチェック
t_bool	check_path_validity(t_game *game, char **map_copy)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (map_copy[y][x] == 'E')
				map_copy[y][x] = '1';
			x++;
		}
		y++;
	}
	if (!check_collectibles_reachable(game, map_copy))
		return (FALSE);
	return (check_exit_reachable(game));
}
