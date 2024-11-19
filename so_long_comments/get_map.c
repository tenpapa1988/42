/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:44:01 by yussaito          #+#    #+#             */
/*   Updated: 2024/11/19 13:57:03 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//Cが0だった場合のエラー処理をしていないので、ここで処理を入れてる
//PとEが複数有る場合には、既にget_map_info関数内で場合分けで処理してる
static t_bool	validate_map_elements(t_game *game)
{
	return (game->map.num_collectible > 0 && game->map.num_exit == 1
		&& game->map.num_s_position == 1);
}

//マップの有効性をチェックする関数。1つでもチェックに引っかかったら FALSEを出す
t_bool	get_map_info(t_list *map, t_game *game)
{
	if (!map || !check_initial_row(map, game))
		return (FALSE);
	map = map->next;
	if (map && !check_middle_rows(map, game))
		return (FALSE);
	while (map && map->next)//check_middle_row関数でチェック済みなので、最後の行まで進める
		map = map->next;
	if (!check_final_row(map))
		return (FALSE);
	if (!validate_map_elements(game))
		return (FALSE);
	return (TRUE);
}

t_bool	is_map_valid(t_game *game)
{
	char	**map_copy;
	t_bool	result;
	size_t	y;

	map_copy = copy_map(game);
	result = check_path_validity(game, map_copy);
	y = 0;
	while (y < game->map.height)
	{
		free(map_copy[y]);
		y++;
	}
	free(map_copy);
	return (result);
}

void	free_visited(t_bool **visited, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		if (visited[i])
			free(visited[i]);
		i++;
	}
	free(visited);
}
