/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:30:56 by yussaito          #+#    #+#             */
/*   Updated: 2024/11/09 13:59:37 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// static int	ft_update(void *game_, size_t x, size_t y)
// {
// 	t_game	*game;

// 	game = (t_game *)game_;
// 	if (x != game->player.x || y != game->player.y)
// 		select_image(game, 'P');
// 	else
// 		return (0);
// 	ft_put_image_to_window(game, game->player.x, game->player.y);
// 	mlx_destroy_image(game->mlx, game->img.img);
// 	select_image(game, '0');
// 	ft_put_image_to_window(game, x, y);
// 	mlx_destroy_image(game->mlx, game->img.img);
// 	game->map.map[y][x] = '0';
// 	x = game->player.x;
// 	y = game->player.y;
// 	if (game->map.map[y][x] == 'C')
// 	{
// 		game->map.num_collectible -= 1;
// 	}
// 	game->map.map[y][x] = 'P';
// 	return (0);
// }

// static void	set_player_position(t_game *game, size_t x, size_t y)
// {
// 	game->player.x = x;
// 	game->player.y = y;
// }

// int	ft_input(int key, void *game_)
// {
// 	size_t	x;
// 	size_t	y;
// 	t_game	*game;

// 	game = (t_game *)game_;
// 	x = game->player.x;
// 	y = game->player.y;
// 	if (key == ESC)
// 		mlx_loop_end(game->mlx);
// 	if (key == W)
// 		game->player.y -= 1;
// 	else if (key == S)
// 		game->player.y += 1;
// 	else if (key == A)
// 		game->player.x -= 1;
// 	else if (key == D)
// 		game->player.x += 1;
// 	else
// 		return (0);
// 	if (can_move(game, game->map.map[game->player.y][game->player.x]))
// 		ft_update(game, x, y);
// 	else
// 		set_player_position(game, x, y);
// 	return (0);
// }

int	ft_input(int key, void *game_)
{
	size_t	x;
	size_t	y;
	t_game	*game;

	game = (t_game *)game_;
	x = game->player.x;
	y = game->player.y;

	if (key == ESC)
		mlx_loop_end(game->mlx);

	// プレイヤーの移動
	if (key == W)
		game->player.y -= 1;
	else if (key == S)
		game->player.y += 1;
	else if (key == A)
		game->player.x -= 1;
	else if (key == D)
		game->player.x += 1;
	else
		return (0);

	// プレイヤーの新しい位置のタイルをチェック
	char next_position = game->map.map[game->player.y][game->player.x];

	// プレイヤーが出口に到達した際のチェック
	if (next_position == 'E' && game->map.num_collectible == 0)
	{
		mlx_loop_end(game->mlx); // 全てのアイテムを集めたのでゲーム終了
		return (0);
	}

	// 通常の移動処理
	if (can_move(game, next_position))
	{
		// 移動前のタイルを復元
		if (game->floor_under_player == 'E')
		{
			select_image(game, 'E');
			ft_put_image_to_window(game, x, y);
			mlx_destroy_image(game->mlx, game->img.img);
		}
		else
		{
			select_image(game, '0');
			ft_put_image_to_window(game, x, y);
			mlx_destroy_image(game->mlx, game->img.img);
		}

		// プレイヤーの新しい位置を描画
		game->floor_under_player = next_position;
		select_image(game, 'P');
		ft_put_image_to_window(game, game->player.x, game->player.y);
		mlx_destroy_image(game->mlx, game->img.img);
	}
	else
	{
		// 移動できない場合は元の位置に戻す
		game->player.x = x;
		game->player.y = y;
	}

	return (0);
}






int	close_window(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

int	minimize_window(t_game *game)
{
	get_image(game);
	return (0);
}
