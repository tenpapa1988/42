/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:16:08 by yussaito          #+#    #+#             */
/*   Updated: 2024/11/20 10:52:20 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_all(t_game *game, char **map, size_t i)
{
	while (i > 0)
		free(map[--i]);
	free(map);
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	error_exit(char *message)
{
	ft_printf("Error\n");
	ft_printf("%s\n", message);
	exit (1);
}

int	open_if_file_is_valid(char *argv1)
{
	int		fd;
	size_t	argv1_len;

	argv1_len = ft_strlen(argv1);//argv[1]はmapファイル。mapファイルは.berのファイル形式なので、最低でも4文字以上ある
	if (argv1_len < 4 || ft_strncmp(argv1 + argv1_len - 4, ".ber", 5))//4文字以下だった場合＆最後の4文字が.berで終わっていない場合にエラー出す
		error_exit("invalid extension");
	fd = open(argv1, O_RDONLY);
	if (fd == -1)//fd == -1はエラーの場合
		error_exit(strerror(errno));
	return (fd);
}

static void	initialize_game(t_game *game, char *program_name)
{
	game->mlx = mlx_init();//MLXの初期化
	if (game->mlx == NULL)
		error_exit("X Server Failed");
	game->mlx_win = mlx_new_window(game->mlx, game->map.width * IMAGE_SIZE,
			game->map.height * IMAGE_SIZE, program_name);//ウインドウの生成
	if (game->mlx_win == NULL)
		error_exit("Failed to create window");
	init_assets_path(game);//画像へのパスを追加
	get_image(game);//アセットパスに基づいて画像のロードを行う
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	if (argc != 2)
		error_exit("invalid argument");
	fd = open_if_file_is_valid(argv[1]);
	game = (t_game){0};//t_gameという構造体のすべてのメンバの値を初期化（0またはNULL）にしている
	get_map_data(fd, &game);
	close(fd);
	initialize_game(&game, argv[0]);//initialize_game関数を発動しているので、画面が一瞬立ち上がってしまう
	if (!is_map_valid(&game))//mapがゲームできるのか？壁で囲われているなどをチェックする
		free_and_exit("No valid path from P to all C and E", &game, NULL, 0);
	mlx_hook(game.mlx_win, E_KEY_PRESS, M_KEY_PRESS, ft_input, &game);//プレーヤーが動くOR ESCで閉じる
	mlx_hook(game.mlx_win, E_WIN_CLOSE, M_WIN_RESIZE, close_window, &game);//Winddowを閉じる
	mlx_hook(game.mlx_win, E_WIN_RESIZE, M_WIN_CLOSE, minimize_window, &game);//WindowをMinimizeする。E_WIN_RESIZEでウインドウフォーカス。Structure NotifyMaskで最小化の動作。minimize_windowで最小化しても画像を表示させておく
	mlx_loop(game.mlx);/プログラミングが終了するまで継続的に存在し続ける関数
	free_all(&game, game.map.map, game.map.height);//freeする
	exit(0);
}
//mlx_hook関数では、第1引数にはイベントを設定する対象のウィンドウ。第2引数は発生したときに反応するイベントの種類。第3引数はイベントマスク。第4引数は指定したイベントが発生したときに実行する関数。第5引数は第4引数の関数に引き継ぐパラメータ。
