/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 08:51:54 by yussaito          #+#    #+#             */
/*   Updated: 2024/11/01 08:22:27 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

const char	*g_assets_path[5] = {
	"assets/wall/wall.xpm",
	"assets/floor/floor.xpm",
	"assets/player/player.xpm",
	"assets/exit/exit.xpm",
	"assets/sprite/sprite.xpm",
};

void	ft_put_image_to_window(t_game *game, size_t x, size_t y)
{
	x *= IMAGE_SIZE;
	y *= IMAGE_SIZE;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, x, y);
}

void	select_image(t_game *game, char c)
{
	char	*path;

	if (c == '1')
		path = (char *)g_assets_path[WALL];
	else if (c == '0')
		path = (char *)g_assets_path[FLOOR];
	else if (c == 'C')
		path = (char *)g_assets_path[COLLECTIBLE];
	else if (c == 'P')
		path = (char *)g_assets_path[PLAYER];
	else if (c == 'E')
		path = (char *)g_assets_path[EXIT];
	else
		path = NULL;
	game->img.img = mlx_xpm_file_to_image(game->mlx, path,
		&game->img.img_height, &game->img.img_width);
	if (game->img.img == NULL)
		error_exit("get_image failed.");
}

void	get_image(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			select_image(game, game->map.map[y][x]);
			ft_put_image_to_window(game, x, y);
			mlx_destroy_image(game->mlx, game->img.img);
			if (game->map.map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
			}
			x++;
		}
		y++;
	}
}

t_bool	can_move(t_game *game, char next_position)
{
	if (next_position == 'E')
	{
		if (game->map.num_collectible == 0)
			mlx_loop_end(game->mlx);
		return (FALSE);
	}
	if (next_position != '1')
	{
		game->move_count += 1;
		ft_printf("move count-> %u\n", game->move_count);
		return (TRUE);	
	}
	return (FALSE);
}
