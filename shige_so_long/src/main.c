/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:16:16 by tshigena          #+#    #+#             */
/*   Updated: 2024/10/18 01:32:15 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_all(t_game game, char **map, size_t i)
{
	while (i > 0 )
		free(map[--i]);
	free(map);
	mlx_clear_window(game.mlx, game.mlx_win);
	mlx_destroy_window(game.mlx, game.mlx_win);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
}

void	error_exit(char *message)
{
	printf("Error\n");
	printf("%s\n", message);
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
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		error_exit(strerror(errno));
	game.mlx_win = mlx_new_window(game.mlx, game.map.width * IMAGE_SIZE, \
		game.map.height * IMAGE_SIZE, argv[0]);
	if (game.mlx_win == NULL)
		error_exit(strerror(errno));
	get_image(&game);
	mlx_hook(game.mlx_win, E_KEY_PRESS, M_KEY_PRESS, ft_input, &game);
	mlx_hook(game.mlx_win, E_WIN_CLOSE, M_WIN_RESIZE, close_window, &game);
	mlx_hook(game.mlx_win, E_WIN_RESIZE, M_WIN_CLOSE, minimize_window, &game);
	mlx_loop(game.mlx);
	free_all(game, game.map.map, game.map.height);
	exit (0);
}
