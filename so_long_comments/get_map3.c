/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:44:01 by yussaito          #+#    #+#             */
/*   Updated: 2024/11/20 09:14:00 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//関数としては、指定されたファイルディスクリプタを読み込んで、マップデータをリスト形式に読み込む
static t_list	*load_map_from_file(int fd, t_game *game)
{
	t_list	*current;
	t_list	head;
	char	*line;

	head.next = NULL;
	current = &head;
	game->map.height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		current->next = ft_lstnew(line);//新しいリストノードを作成し、current->nextでノードを接続
		if (!current->next)
		{
			free(line);
			error_exit_with_lstclear(head.next,
				"Failed to allocate memory for list node");
		}
		current = current->next;
		game->map.height++;//1行を読み込む毎にインクリメントをする
		line = get_next_line(fd);
	}
	if (head.next == NULL || head.next->content == NULL)
		error_exit_with_lstclear(head.next, "Invalid map");
	return (head.next);
}
//ゲームのマップを2次元配列に変換する＆プレイヤーのスタート位置を記録する関数
static void	initialize_game_map(t_game *game, t_list *map_list)
{
	size_t	i;
	size_t	j;

	i = 0;
	move_list_to_double_pointer(game, map_list);
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == 'P')//ここでPの位置を記録する
			{
				game->player.x = j;
				game->player.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	get_map_data(int fd, t_game *game)
{
	t_list	*map_list;

	map_list = load_map_from_file(fd, game);
	if (get_map_info(map_list, game) == FALSE)
		error_exit_with_lstclear(map_list, "Invalid map");
	initialize_game_map(game, map_list);
}

//各マスを訪問済か？を記録するための二次元配列
t_bool	**allocate_visited(t_game *game)
{
	t_bool	**visited;
	size_t	i;
	size_t	j;

	i = 0;
	visited = (t_bool **)ft_calloc(game->map.height, sizeof(t_bool *));//高さに基づいて動的に確保
	if (!visited)
		error_exit("Memory allocation failed for visited array");
	while (i < game->map.height)
	{
		visited[i] = (t_bool *)ft_calloc(game->map.width, sizeof(t_bool));//width側に対して動的に確保
		if (!visited[i])
			error_exit("Memory allocation failed for visited row");
		j = 0;
		while (j < game->map.width)
		{
			if (visited[i][j] != FALSE)
				ft_printf("Error: visited[%zu][%zu] isn't FALSE\n", i, j);
			j++;
		}
		i++;
	}
	return (visited);
}

//深さ優先探索でPの位置からvistedをTRUEにしてく
void	dfs(t_game *game, int x, int y, t_bool **visited)
{
	if (x < 0 || y < 0 || x >= (int)game->map.width
		|| y >= (int)game->map.height
		|| game->map.map[y][x] == '1' || visited[y][x])
		return ;//探索範囲がマップの外や1にぶつかったとき、すでに訪問済みの場合には終了する
	visited[y][x] = TRUE;
	dfs(game, x + 1, y, visited);//再起なので、returnで抜けるまではここを行う
	dfs(game, x - 1, y, visited);
	dfs(game, x, y + 1, visited);
	dfs(game, x, y - 1, visited);
}
