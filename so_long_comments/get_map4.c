/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:44:01 by yussaito          #+#    #+#             */
/*   Updated: 2024/11/19 15:15:55 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error_exit_with_lstclear(t_list *map, char *message)
{
	ft_lstclear(&map, free);
	error_exit(message);
}

void	free_and_exit(char *message, t_game *game,
			char **map_copy, size_t height)
{
	size_t	i;

	i = 0;
	if (game->map.map)
	{
		while (i < game->map.height)
		{
			if (game->map.map[i])
				free(game->map.map[i]);
			i++;
		}
		free(game->map.map);
		game->map.map = NULL;
	}
	free_all(game, map_copy, height);
	ft_printf("Error\n");
	ft_printf("%s\n", message);
	exit(1);
}

//マップを格納するための 二次元配列（char **）用のメモリを確保。
static char	**allocate_map_memory(size_t height, t_list *map)//height+1なのはNULL終端の確保のため
{
	char	**map_array;

	map_array = (char **)ft_calloc(height + 1, sizeof(char *));
	if (map_array == NULL)
		error_exit_with_lstclear(map, "failed malloc");
	return (map_array);
}

//リストに格納されたマップデータを二次元配列（char **）にコピー
static void	copy_list_to_map(char **map_array, t_list *map, size_t height)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	tmp = map;
	while (i < height)
	{
		map_array[i] = ft_strdup(tmp->content);
		if (!map_array[i])
		{
			while (i > 0)
			{
				free(map_array[--i]);//i = 2で失敗した場合にはメモリを確保していた1から開放していく必要があるので--iになってる
				map_array[i] = NULL;
			}
			free(map_array);
			map_array = NULL;
			error_exit_with_lstclear(map, "failed malloc");
		}
		tmp = tmp->next;
		i++;
	}
	ft_lstclear(&map, free);
}

void	move_list_to_double_pointer(t_game *game, t_list *map)
{
	game->map.map = allocate_map_memory(game->map.height, map);
	copy_list_to_map(game->map.map, map, game->map.height);
}
