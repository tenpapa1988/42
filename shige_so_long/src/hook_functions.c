/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:01:47 by tshigena          #+#    #+#             */
/*   Updated: 2024/11/05 16:23:19 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_update(void *game_, size_t x, size_t y)
{
	t_game	*game;

	game = (t_game *)game_;
	if (x != game->player.x || y != game->player.y)
		select_image(game, 'P');
	else
		return (0);
	ft_put_image_to_window(game, game->player.x, game->player.y);//新しい場所にPを表示
	mlx_destroy_image(game->mlx, game->img.img);//Pのメモリを解放（開放しても、画像は表示されたままになる仕様らしい）
	select_image(game, '0');//背景画像を取得
	ft_put_image_to_window(game, x, y);//背景画像を元の位置にセット
	mlx_destroy_image(game->mlx, game->img.img);//メモリを開放
	game->map.map[y][x] = '0';//元の位置のマップを0（背景画像）にする
	x = game->player.x;//位置を更新
	y = game->player.y;//位置を更新
	if (game->map.map[y][x] == 'C')//もし新しいマップの位置にCがあったらif文に入る
	{
		game->map.num_collectible -= 1;//Cを減らす
	}
	game->map.map[y][x] = 'P';//その後にPを表示（Cの上書き）
	return (0);
}

//ここでの位置の再設定は不要に見えるけど、Bonusをやろうとした際や保険として再度設定していると考えられる
static void	set_player_position(t_game *game, size_t x, size_t y)
{
	game->player.x = x;
	game->player.y = y;
}

int	ft_input(int key, void *game_)
{
	size_t	x;
	size_t	y;
	t_game	*game;

	game = (t_game *)game_;//_を付けるとポインタ変数であることを意味するらしい（慣例的に）
	x = game->player.x;
	y = game->player.y;
	if (key == ESC)//ESCだったらclose_window関数と同様に閉じる
		mlx_loop_end(game->mlx);
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
	if (can_move(game, game->map.map[game->player.y][game->player.x]))
		ft_update(game, x, y);
	else
		set_player_position(game, x, y);
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
