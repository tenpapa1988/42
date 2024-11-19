/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:44:16 by yussaito          #+#    #+#             */
/*   Updated: 2024/11/19 13:46:32 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

size_t	map_row_len(const char *row)
{
	size_t	i;

	i = 0;
	if (!row)
		return (0);
	while (*row)
	{
		if (ft_strchr("10CPE", *row))
			i++;
		row++;
	}
	return (i);
}

t_bool	check_initial_row(t_list *map, t_game *game)
{
	if (!map || !map->content)
		return (FALSE);
	game->map.width = map_row_len(map->content);//ここでwidthを計測＆代入
	if (!map->next || !check_map_dimensions(map, game->map.width)
		|| !check_edge_row(map->content))
		return (FALSE);
	return (TRUE);
}

//最初と最後の行以外をチェックする関数
t_bool	check_middle_row(char *row, char *prev_row,
						char *next_row, t_game *game)
{
	size_t	i;

	i = 0;
	if (!check_row_borders(row, game->map.width))
		return (FALSE);
	while (row[i])
	{
		if (!check_row_elements(row, game, i))
			return (FALSE);
		if (row[i] == 'E' && check_exit_surrounded(row, prev_row, next_row, i))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
//上下左右の壁のチェックのために利用
t_bool	check_middle_rows(t_list *map, t_game *game)
{
	char	*prev_row;
	char	*next_row;

	if (!map || !map->content)
		return (FALSE);
	prev_row = map->content;
	while (map && map->next)
	{
	next_row = map->next->content;
		if (!check_middle_row(map->content, prev_row, next_row, game))
			return (FALSE);
		prev_row = map->content;
	map = map->next;
	}
	return (TRUE);
}

//最後の行をチェックする。ロジックはcheck_initial_rowと同じ
t_bool	check_final_row(t_list *map)
{
	if (!map || !map->content)
		return (FALSE);
	if (!check_edge_row(map->content))
		return (FALSE);
	return (TRUE);
}
