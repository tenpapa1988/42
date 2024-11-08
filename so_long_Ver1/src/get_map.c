/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:44:01 by yussaito          #+#    #+#             */
/*   Updated: 2024/11/08 11:09:09 by yussaito         ###   ########.fr       */
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

static void	move_list_to_double_pointer(t_game *game, t_list *map)
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
		game->map.map[i] = ft_strdup(tmp->content);
		if (!game->map.map[i])
			error_exit_with_lstclear(map, "faild malloc for map row");
		tmp = tmp->next;
		i++;
	}
	ft_lstclear(&map, free);
}

void	get_map_data(int fd, t_game *game)
{
	t_list	*current;
	t_list	head;
	char	*line;

	game->map.height = 0;
	errno = 0;
	head.next = NULL;
	current = &head;
	line = get_next_line(fd);
	while (line != NULL)
	{
		current->next = ft_lstnew(line);
		if (!current->next)
		{
			free(line);
			error_exit_with_lstclear(head.next, "Allocate Fail");
		}
		current = current->next;
		game->map.height++;
		line = get_next_line(fd);
	}
	if (head.next == NULL || head.next->content == NULL
		|| get_map_info(head.next, game) == FALSE)
		error_exit_with_lstclear(head.next, "invalid map");
	move_list_to_double_pointer(game, head.next);
}
