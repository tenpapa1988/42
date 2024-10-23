/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:44:16 by yussaito          #+#    #+#             */
/*   Updated: 2024/10/23 11:28:06 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error_exit_with_lsclear(t_list *map, char *message)
{
	ft_lstclear(&map, free);
	error_exit(message);
}

void	move_list_to_double_pointer(t_game *game, t_list *map)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	game->map.map = (char **)ft_calloc(game->map.height + 1, sizeof(char *));
	if (game->map.map == NULL)
		error_exit_with_lsclear(map, "failed malloc");
	tmp = map;
	while (i < game->map.height)
	{
		game->map.map[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	ft_lstclear(&map, NULL);
}