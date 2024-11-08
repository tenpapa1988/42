/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:44:16 by yussaito          #+#    #+#             */
/*   Updated: 2024/11/08 11:32:50 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_bool	check_map_dimensions(t_list *map, size_t width)
{
	while (map)
	{
		if (!map->content || map_row_len(map->content) != width)
			return (FALSE);
		map = map->next;
	}
	return (TRUE);
}

t_bool	check_edge_row(char *row)
{
	while (*row)
	{
		if (*row != '1' && *row != '\n')
			return (FALSE);
		row++;
	}
	return (TRUE);
}

t_bool	check_row_borders(char *row, size_t width)
{
	if (row[0] != '1' || row[width - 1] != '1')
		return (FALSE);
	return (TRUE);
}

t_bool	check_row_elements(char *row, t_game *game, size_t i)
{
	if (ft_strchr("10CPE\n", row[i]) == NULL)
		return (FALSE);
	if (row[i] == 'C')
		game->map.num_collectible++;
	if (row[i] == 'P')
	{
		game->map.num_s_position++;
		if (game->map.num_s_position > 1)
			return (FALSE);
	}
	if (row[i] == 'E')
	{
		game->map.num_exit++;
		if (game->map.num_exit > 1)
			return (FALSE);
	}
	return (TRUE);
}

t_bool	check_exit_surrounded(char *row, char *prev_row,
							char *next_row, size_t index)
{
	if (!prev_row || !next_row)
		return (FALSE);
	return (prev_row[index] == '1' && next_row[index] == '1'
		&& row[index - 1] == '1' && row[index + 1] == '1');
}
