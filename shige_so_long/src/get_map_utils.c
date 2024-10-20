/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:25:14 by tshigena          #+#    #+#             */
/*   Updated: 2024/10/18 16:30:33 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_exit_with_lstclear(t_list *map, char *message)
{
	ft_lstclear(&map, free);
	error_exit(message);
}

void	move_list_to_double_pointer(t_game *game, t_list *map)//リンクリストを2次元配列に入れ替える関数。2次元配列の方がリンクリストよりも処理速度が早くなるので、こっちが望ましい
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	game->map.map = (char **)ft_calloc(game->map.height + 1, sizeof(char *));
	if (game->map.map == NULL)
		error_exit_with_lstclear(map, "failed malloc");
	tmp = map;
	while (i < game->map.height)
	{
		game->map.map[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	ft_lstclear(&map, NULL);
}
