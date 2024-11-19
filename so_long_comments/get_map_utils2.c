/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:44:16 by yussaito          #+#    #+#             */
/*   Updated: 2024/11/19 13:48:36 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//mapの行の長さがwidthと一致しない場合にはFALSEを返す関数
//これをすべての行でチェックする。initial_rowの段階ですべての行のwidthチェックを終える
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

//最初の行が1じゃなかったらFALSE
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
//行の最初と最後が1じゃなかったらFALSE
t_bool	check_row_borders(char *row, size_t width)
{
	if (row[0] != '1' || row[width - 1] != '1')
		return (FALSE);
	return (TRUE);
}

//行内のチェックをする。10CPE\nだけで構成されているかをチェック。CとPとEの数を数える。PとEが1以上ならエラー出す
t_bool	check_row_elements(char *row, t_game *game, size_t i)
{
	if (ft_strchr("10CPE\n", row[i]) == NULL)//10CPE\n以外が入ってきたらNULLを出す
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

//prev_rowは1つ上の行、next_rowは1つ下の行が入っているので、indexさえ分かれば上下を表現できる
//これで上下左右が囲まれているのか？をチェックしている
//ただ、実際には探索でもチェックしているので、不要では有るが、昔の名残ってことで
t_bool	check_exit_surrounded(char *row, char *prev_row,
							char *next_row, size_t index)
{
	if (!prev_row || !next_row)
		return (FALSE);
	return (prev_row[index] == '1' && next_row[index] == '1'
		&& row[index - 1] == '1' && row[index + 1] == '1');
}
