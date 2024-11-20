/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 08:51:54 by yussaito          #+#    #+#             */
/*   Updated: 2024/11/20 10:18:53 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//t_game構造体にあるonst char *assets_path[5]にそれぞれパスを代入している
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
	x *= IMAGE_SIZE;//ピクセル座標に変換。マップ座標（1, 1）みたいなやつにピクセルのサイズを掛け算すると画面に表示させる際にピクセルの大きさに合わせた表示が可能になる
	y *= IMAGE_SIZE;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, x, y);//画像を出力
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
			&game->img.img_height, &game->img.img_width);//画像ファイルをMLXで仕使用できる形式に変換する
	if (game->img.img == NULL)
		error_exit("get_image failed.");//変換に失敗したらエラー
}

//マップデータを調べて、それぞれの座標に当てはまる画像を出力していく
void	get_image(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)//まずは横に進んでいって、画像を表示させる
		{
			select_image(game, game->map.map[y][x]);//座標毎にパスを選択＆画像ファイルをロードして描写可能な形式に変換
			ft_put_image_to_window(game, x, y);//select_imageでロードしたファイルを指定された座標に表示
			mlx_destroy_image(game->mlx, game->img.img);//使用済みの画像を解放する→ウィンドウのバッファ内に保存されるので画像は消えない
			x++;
		}
		y++;
	}
}
//Eか1で条件ついてる。EはCが残っていたら移動を拒否。全て集めていればゴール
//1の場合にはmove_countを1追加＆出力
t_bool	can_move(t_game *game, char next_position)
{
	if (next_position == 'E')
	{
		if (game->map.num_collectible > 0)
			return (FALSE);
		ft_printf("Congratulations! You've cleared the game!\n");
		mlx_loop_end(game->mlx);
		return (TRUE);
	}
	if (next_position != '1')
	{
		game->move_count += 1;
		ft_printf("move count -> %u\n", game->move_count);
		return (TRUE);
	}
	return (FALSE);
}
