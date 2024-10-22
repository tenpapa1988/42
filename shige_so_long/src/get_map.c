/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:10:10 by tshigena          #+#    #+#             */
/*   Updated: 2024/10/20 14:35:34 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static t_bool	check_middle_row(char *row, size_t width, t_game *game)
{
	if (row[0] != '1' || row[width - 1] != '1')
		return (FALSE);
	while (*row)
	{
		if (ft_strchr("10CPE\n", *row) == NULL)
			return (FALSE);
		if (*row == 'C')
			game->map.num_collectible += 1;
		if (*row == 'P')
		{
			game->map.num_s_position += 1;
			if (game->map.num_s_position > 1)
				return (FALSE);
		}
		if (*row == 'E')
			game->map.num_exit += 1;//ここでexitが2つ上のエラーハンドリングを行っていないので、行う必要がある（Pのときと同じように書けばよいはず）
		row++;
	}
	return (TRUE);
}

static t_bool	check_edge_row(char *row)
{
	while (*row)
	{
		if (*row != '1' && *row != '\n')
			return (FALSE);
		row++;
	}
	return (TRUE);
}

static size_t	map_row_len(const char *row)
{
	size_t	i;

	i = 0;
	while (*row != '\0')
	{
		if (ft_strchr("10CPE", *row))
			i++;
		row++;
	}
	return (i);
}

static t_bool	get_map_info(t_list *map, t_game *game)
{
	size_t	i;

	i = 0;
	game->map.width = map_row_len(map->content);
	while (map->content != NULL)	{
		if (i != 0 && game->map.width != map_row_len(map->content))
			return (FALSE);
		if (i == 0 || i + 1 == game->map.height)
		{
			if (check_edge_row(map->content) == FALSE)
				return (FALSE);
		}
		else
		{
			if (check_middle_row(map->content, game->map.width, game) == FALSE)
				return (FALSE);
		}
		i++;
		map = map->next;
	}
	if (!game->map.num_collectible || !game->map.num_exit
		|| !game->map.num_s_position)
		return (FALSE);
	return (TRUE);
}

void	get_map_data(int fd, t_game *game)
{
	t_list	*current;
	t_list	head;

	game->map.height = 0;//マップファイルの高さ（行の数）を計測するために初期化
	errno = 0;
	head.next = NULL;//headの次にポインタを一旦NULLに。Push Swapで利用した番兵ノード的なやつ
	current = &head;
	while (1)//mapファイルの中身を構造体に入れつつ、height（行の数）をカウントしている
	{
		current->next = ft_lstnew(get_next_line(fd));//get_next_lineで取得した1行をft_lstnewによって新しいリンクリストノードを作成する
		if ((!current->next || !current->next->content) && errno)
			error_exit_with_lstclear(head.next, strerror(errno));
		current = current->next;
		if (current->content == NULL)
			break ;
		game->map.height++;
	}
	if (head.next->content == NULL || get_map_info(head.next, game) == FALSE)
		error_exit_with_lstclear(head.next, "invalid map");
	move_list_to_double_pointer(game, head.next);
}
