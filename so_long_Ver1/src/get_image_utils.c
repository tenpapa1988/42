/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 08:51:54 by yussaito          #+#    #+#             */
/*   Updated: 2024/11/16 09:24:11 by yussaito         ###   ########.fr       */
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

void get_image(t_game *game)
{
    size_t y;
    size_t x;

    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            select_image(game, game->map.map[y][x]);
            ft_put_image_to_window(game, x, y);
            mlx_destroy_image(game->mlx, game->img.img);
            x++;
        }
        y++;
    }
}

t_bool	can_move(t_game *game, char next_position)
{
	// 1. 次の位置が 'E'（出口）の場合
	if (next_position == 'E')
	{
		// 2. まだコレクタブルが残っている場合、通り抜けられない
		if (game->map.num_collectible > 0)
			return (FALSE);

		// 3. コレクタブルを全て集めていればゲームクリア
		ft_printf("Congratulations! You've cleared the game!\n");
		mlx_loop_end(game->mlx); // ゲームを終了
		return (TRUE);
	}

	// 4. 次の位置が壁 ('1') 以外なら移動を許可
	if (next_position != '1')
	{
		game->move_count += 1;
		ft_printf("move count -> %u\n", game->move_count);
		return (TRUE);
	}

	// 5. その他の場合は移動できない
	return (FALSE);
}


// void	get_image(t_game *game)
// {
// 	size_t	y;
//	size_t	x;

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