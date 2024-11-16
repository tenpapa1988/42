/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:44:01 by yussaito          #+#    #+#             */
/*   Updated: 2024/11/16 14:49:20 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static t_bool	validate_map_elements(t_game *game)
{
	return (game->map.num_collectible > 0 && game->map.num_exit == 1
		&& game->map.num_s_position == 1);
}

static t_bool	get_map_info(t_list *map, t_game *game)
{
	if (!map || !check_initial_row(map, game))
		return (FALSE);
	map = map->next;
	if (map && !check_middle_rows(map, game))
		return (FALSE);
	while (map && map->next)
		map = map->next;
	if (!check_final_row(map))
		return (FALSE);
	if (!validate_map_elements(game))
	{
		return (FALSE);
	}
	return (TRUE);
}

static void	error_exit_with_lstclear(t_list *map, char *message)
{
	ft_lstclear(&map, free);
	error_exit(message);
}

void free_and_exit(char *message, t_game *game, char **map_copy, size_t height)
{
    // メモリの解放
    free_all(game, map_copy, height);

    // エラーメッセージの出力
    printf("Error\n");
    printf("%s\n", message);

    // プログラム終了
    exit(1);
}

static void	move_list_to_double_pointer(t_game *game, t_list *map)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	game->map.map = (char **)ft_calloc(game->map.height + 1, sizeof(char *));
   if (game->map.map == NULL)
    {
        ft_lstclear(&map, free);
        error_exit("failed malloc for map");
    }
	tmp = map;
	while (i < game->map.height)
	{
		game->map.map[i] = ft_strdup(tmp->content);
        if (!game->map.map[i])
        {
            free_all(game, game->map.map, i);
            ft_lstclear(&map, free);
            error_exit("failed malloc for map row");
        }
		tmp = tmp->next;
		i++;
	}
	ft_lstclear(&map, free);
}

void get_map_data(int fd, t_game *game)
{
    t_list *current;
    t_list head;
    char *line;
    size_t i = 0;

    game->map.height = 0;
    errno = 0;
    head.next = NULL;
    current = &head;
    while ((line = get_next_line(fd)) != NULL)
	{
        current->next = ft_lstnew(line);
        if (!current->next)
		{
            free(line);
            error_exit_with_lstclear(head.next, "Failed to allocate memory for list node");
        }
        current = current->next;
        game->map.height++;
        printf("Reading line: %s", line);
    }
	if (head.next == NULL || head.next->content == NULL ||
		get_map_info(head.next, game) == FALSE)
	{
		error_exit_with_lstclear(head.next, "Invalid map");
	}
    move_list_to_double_pointer(game, head.next);

    // プレイヤーの位置をここで設定して、get_image() では再設定しない
    for (i = 0; i < game->map.height; i++) {
        for (size_t j = 0; j < game->map.width; j++) {
            if (game->map.map[i][j] == 'P') {
                game->player.x = j;
                game->player.y = i;
                printf("Player found at position (during map loading): (%zu, %zu)\n", j, i);
                return;
            }
        }
    }
}

// 2次元配列を動的に確保して初期化する関数
t_bool **allocate_visited(t_game *game)
{
    t_bool **visited;
    size_t i;

    // callocを使用して確保し、すべての要素をFALSEで初期化
    visited = (t_bool **)calloc(game->map.height, sizeof(t_bool *));
    if (!visited)
        error_exit("Memory allocation failed for visited array");

    for (i = 0; i < game->map.height; i++)
    {
        visited[i] = (t_bool *)calloc(game->map.width, sizeof(t_bool));
        if (!visited[i])
            error_exit("Memory allocation failed for visited row");

        // 確実に初期化されているか確認
        for (size_t j = 0; j < game->map.width; j++)
        {
            if (visited[i][j] != FALSE)
            {
                printf("Error: visited[%zu][%zu] is not FALSE after initialization\n", i, j);
            }
        }
    }
    return visited;
}


void print_visited(t_game *game, t_bool **visited)
{
    size_t y, x;

    printf("Visited cells:\n");
    for (y = 0; y < game->map.height; y++)
    {
        for (x = 0; x < game->map.width; x++)
        {
            if (visited[y][x])
                printf("V");
            else
                printf(".");
        }
        printf("\n");
    }
    printf("\n");
}


// DFS探索関数
void dfs(t_game *game, char **map, int x, int y, t_bool **visited)
{
    if (x < 0 || y < 0 || x >= (int)game->map.width || y >= (int)game->map.height ||
        map[y][x] == '1' || visited[y][x])
        return;

    printf("DFS: Visiting (%d, %d) -> %c\n", x, y, map[y][x]);
    visited[y][x] = TRUE;

    // 訪問後の `visited` 配列の状態をログ
    printf("Visited cells after visiting (%d, %d):\n", x, y);
    print_visited(game, visited);

    dfs(game, map, x + 1, y, visited);
    dfs(game, map, x - 1, y, visited);
    dfs(game, map, x, y + 1, visited);
    dfs(game, map, x, y - 1, visited);
}


t_bool check_reachable(t_game *game, t_bool **visited, char target)
{
    size_t x, y;
    t_bool reachable = TRUE;

    for (y = 0; y < game->map.height; y++)
    {
        for (x = 0; x < game->map.width; x++)
        {
            if (game->map.map[y][x] == target && !visited[y][x])
            {
                printf("Error: %c at (%zu, %zu) is not reachable\n", target, x, y);
                reachable = FALSE;
            }
        }
    }
    return reachable;
}

t_bool is_map_valid(t_game *game)
{
    t_bool **visited1, **visited2;
    size_t y;
    char **map_copy1;
    t_bool all_collectibles_reachable, exit_reachable;

    // **1つ目のマップコピーを作成**
	map_copy1 = (char **)malloc(sizeof(char *) * game->map.height);
	if (!map_copy1)
		free_and_exit("Failed to allocate memory for map copy", game, NULL, 0);

	for (y = 0; y < game->map.height; y++)
	{
		map_copy1[y] = ft_strdup(game->map.map[y]);
		if (!map_copy1[y])
		{
			free_and_exit("Failed to allocate memory for map row", game, map_copy1, y);
		}
	}

    // **1回目のDFS探索 (コレクタブル用)** 
    visited1 = allocate_visited(game);
    if (!visited1)
    {
        for (y = 0; y < game->map.height; y++)
            free(map_copy1[y]);
        free(map_copy1);
        return FALSE;
    }

    // 出口を壁として扱う
    for (y = 0; y < game->map.height; y++)
    {
        for (size_t x = 0; x < game->map.width; x++)
        {
            if (map_copy1[y][x] == 'E')
                map_copy1[y][x] = '1';
        }
    }
    dfs(game, map_copy1, game->player.x, game->player.y, visited1);
    print_visited(game, visited1);

    // **1回目のチェック: 全てのコレクタブルが到達可能か**
    all_collectibles_reachable = check_reachable(game, visited1, 'C');
    if (!all_collectibles_reachable)
    {
        free_visited(visited1, game->map.height);
        for (y = 0; y < game->map.height; y++)
            free(map_copy1[y]);
        free(map_copy1);
        return FALSE;
    }

    // **2回目のDFS探索 (出口用)**
    free_visited(visited1, game->map.height);
    visited2 = allocate_visited(game);
    if (!visited2)
    {
        for (y = 0; y < game->map.height; y++)
            free(map_copy1[y]);
        free(map_copy1);
        return FALSE;
    }

    dfs(game, game->map.map, game->player.x, game->player.y, visited2);
    print_visited(game, visited2);

    // **2回目のチェック: 出口が到達可能か**
    exit_reachable = check_reachable(game, visited2, 'E');
    if (!exit_reachable)
    {
        free_visited(visited2, game->map.height);
        for (y = 0; y < game->map.height; y++)
            free(map_copy1[y]);
        free(map_copy1);
        return FALSE;
    }

    // **メモリ解放**
    free_visited(visited2, game->map.height);
    for (y = 0; y < game->map.height; y++)
        free(map_copy1[y]);
    free(map_copy1);

    return TRUE;
}

void free_visited(t_bool **visited, size_t height)
{
    for (size_t i = 0; i < height; i++)
    {
        if (visited[i])
            free(visited[i]);
    }
    free(visited);
}







