/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:08:41 by tshigena          #+#    #+#             */
/*   Updated: 2024/11/04 10:21:17 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

const char	*g_assets_path[5] = {
	"assets/wall/wall.xpm",
	"assets/floor/floor.xpm",
	"assets/player/player2.xpm",
	"assets/exit/exit2.xpm",
	"assets/sprite/sprite2.xpm",
};

//select_image関数で取得した画像をこの関数でWindowに表示させる
void	ft_put_image_to_window(t_game *game, size_t x, size_t y)
{
	x *= IMAGE_SIZE;
	y *= IMAGE_SIZE;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, x, y);
}

//文字に応じて画像を取得＆mlx_xpm_file_to_imageで当てはめる
void	select_image(t_game *game, char c)
{
	char	*path;

	if (c == '1')
		path = (char *)g_assets_path[WALL];//ヘッダーファイルのe_componentsにて定義されている。WALL=0なので、g_asets_path[0]と連動している
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
	game->img.img = mlx_xpm_file_to_image(game->mlx, path, \
		&game->img.img_height, &game->img.img_width);//game->img.imgに画像データを格納する
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
			mlx_destroy_image(game->mlx, game->img.img);//既にgame->img.imgを使用したので、ここで解放
			if (game->map.map[y][x] == 'P')//ダブルポインタをmove_list_to_double_pointer関数で実現してる。yは縦、xは横。Pの位置を記録してる
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
	if (next_position == 'E')//Exitの場合にCが0か？をチェックして、0なら閉じる
	{
		if (game->map.num_collectible == 0)
			mlx_loop_end(game->mlx);
		return (FALSE);
	}
	if (next_position != '1')//1じゃなければ動く
	{
		game->move_count += 1;
		printf("move count-> %zu\n", game->move_count);
		return (TRUE);
	}
	return (FALSE);
}
