/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:30:56 by yussaito          #+#    #+#             */
/*   Updated: 2024/11/20 10:27:36 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//プレイヤーが移動後のゲーム画面を更新する関数
static int	ft_update(void *game_, size_t x, size_t y)
{
	t_game	*game;

	game = (t_game *)game_;
	if (x != game->player.x || y != game->player.y)
		select_image(game, 'P');//移動していたらPの画像を読み込む。移動してなければそのまま抜ける
	else
		return (0);
	ft_put_image_to_window(game, game->player.x, game->player.y);選択した画像を移動後の座標に描画
	mlx_destroy_image(game->mlx, game->img.img);//メモリを解放
	select_image(game, '0');//移動前の位置に描画するための0の画像を呼び出し
	ft_put_image_to_window(game, x, y);//移動前の位置に空白を描画
	mlx_destroy_image(game->mlx, game->img.img);//メモリを解放
	game->map.map[y][x] = '0';移動前を更新
	x = game->player.x;//プレイヤーの位置を更新
	y = game->player.y;
	if (game->map.map[y][x] == 'C')//プレイヤーの位置にCがあったらcollectibleを1減らす
	{
		game->map.num_collectible -= 1;
	}
	game->map.map[y][x] = 'P';//マップを更新後にPの位置を更新
	return (0);
}

//can_move関数で移動ができない場合には、更新したPの位置を戻す必要が有るので、そのための関数
static void	set_player_position(t_game *game, size_t x, size_t y)
{
	game->player.x = x;
	game->player.y = y;
}
//キーボードからの入力をさばく関数
int	ft_input(int key, void *game_)
{
	size_t	x;
	size_t	y;
	t_game	*game;

	game = (t_game *)game_;//void* 型の game_ を、ゲームの構造体型である t_game* にキャスト
	x = game->player.x;
	y = game->player.y;
	if (key == ESC)
		mlx_loop_end(game->mlx);//ESCだったらclose_window関数と同様に閉じる
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
		set_player_position(game, x, y);//移動できない場合に、元の位置に戻すため
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
