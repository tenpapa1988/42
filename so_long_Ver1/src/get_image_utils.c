/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 08:51:54 by yussaito          #+#    #+#             */
/*   Updated: 2024/11/09 14:02:57 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_assets_path(t_game *game)
{
	game->assets_path[WALL] = "assets/wall/wall.xpm";
	game->assets_path[FLOOR] = "assets/floor/floor.xpm";
	game->assets_path[PLAYER] = "assets/player/player.xpm";
	game->assets_path[EXIT] = "assets/exit/exit.xpm";
	game->assets_path[COLLECTIBLE] = "assets/sprite/sprite.xpm";
}

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
		path = (char *)game->assets_path[WALL];
	else if (c == '0')
		path = (char *)game->assets_path[FLOOR];
	else if (c == 'C')
		path = (char *)game->assets_path[COLLECTIBLE];
	else if (c == 'P')
		path = (char *)game->assets_path[PLAYER];
	else if (c == 'E')
		path = (char *)game->assets_path[EXIT];
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
				if (game->player_on_exit)
				{
					select_image(game, 'E');
					ft_put_image_to_window(game, x, y);
					mlx_destroy_image(game->mlx, game->img.img);
				}
				select_image(game, 'P');
				ft_put_image_to_window(game, x, y);
				mlx_destroy_image(game->mlx, game->img.img);
				game->player.x = x;
				game->player.y = y;
				if (game->player_on_exit)
					game->floor_under_player = 'E';
				else
					game->floor_under_player = '0';
			}
			x++;
		}
		y++;
	}
}

t_bool	can_move(t_game *game, char next_position)
{
    // デバッグメッセージを追加
    ft_printf("can_move: next_position = %c, collectibles left = %d\n", next_position, game->map.num_collectible);

    if (next_position == 'E')
    {
        if (game->map.num_collectible > 0)
        {
            game->player_on_exit = 1;
            return (TRUE);
        }
        ft_printf("All collectibles gathered! Exiting...\n");
        mlx_loop_end(game->mlx);
        return (FALSE);
    }

    if (next_position != '1')
    {
        if (next_position == 'C')
        {
            game->map.num_collectible--;
            ft_printf("Collectible collected! Remaining: %d\n", game->map.num_collectible);
        }

        game->move_count++;
        ft_printf("move count-> %u\n", game->move_count);
        return (TRUE);
    }

    return (FALSE);
}


// void	get_image(t_game *game)
// {
// 	size_t	y;
// 	size_t	x;

// 	y = 0;
// 	while (y < game->map.height)
// 	{
// 		x = 0;
// 		while (x < game->map.width)
// 		{
// 			select_image(game, game->map.map[y][x]);
// 			ft_put_image_to_window(game, x, y);
// 			mlx_destroy_image(game->mlx, game->img.img);
// 			if (game->map.map[y][x] == 'P')
// 			{
// 				game->player.x = x;
// 				game->player.y = y;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }