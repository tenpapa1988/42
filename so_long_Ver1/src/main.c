/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:16:08 by yussaito          #+#    #+#             */
/*   Updated: 2024/11/16 14:48:46 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void free_all(t_game *game, char **map, size_t i)
{
    // mapの各行を解放
    if (map)
    {
        while (i > 0)
            free(map[--i]);
        free(map);
    }

    // game->map.mapの各行を解放
    if (game->map.map)
    {
        for (i = 0; i < game->map.height; i++)
        {
            if (game->map.map[i])
            {
                free(game->map.map[i]);
                game->map.map[i] = NULL; // ポインタをNULLに設定
            }
        }
        free(game->map.map);
        game->map.map = NULL; // ポインタをNULLに設定
    }

    // グラフィック関連のメモリ解放
    if (game->mlx_win)
    {
        mlx_destroy_window(game->mlx, game->mlx_win);
        game->mlx_win = NULL;
    }
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
        game->mlx = NULL;
    }
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

	argv1_len = ft_strlen(argv1);
	if (argv1_len < 4 || ft_strncmp(argv1 + argv1_len - 4, ".ber", 5))
		error_exit("invalid extension");
	fd = open(argv1, O_RDONLY);
	if (fd == -1)
		error_exit(strerror(errno));
	return (fd);
}

static void	initialize_game(t_game *game, char *program_name)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		free_all(game, game->map.map, game->map.height);
		error_exit("X Server Failed");
	}
	game->mlx_win = mlx_new_window(game->mlx, game->map.width * IMAGE_SIZE,
				game->map.height * IMAGE_SIZE, program_name);
	if (game->mlx_win == NULL)
	{
		free_all(game, game->map.map, game->map.height);
		error_exit("Failed to create window");
	}
	init_assets_path(game);
	get_image(game);
}

int main(int argc, char **argv)
{
    t_game game;
    int fd;

    if (argc != 2)
        free_and_exit("Invalid argument", &game, NULL, 0);
    fd = open_if_file_is_valid(argv[1]);
    game = (t_game){0};
    get_map_data(fd, &game);
    close(fd);
    if (!is_map_valid(&game))
        free_and_exit("No valid path from P to all C and E", &game, NULL, 0);
    initialize_game(&game, argv[0]);
    mlx_hook(game.mlx_win, E_KEY_PRESS, M_KEY_PRESS, ft_input, &game);
    mlx_hook(game.mlx_win, E_WIN_CLOSE, M_WIN_RESIZE, close_window, &game);
    mlx_hook(game.mlx_win, E_WIN_RESIZE, M_WIN_CLOSE, minimize_window, &game);
    mlx_loop(game.mlx);
    free_all(&game, game.map.map, game.map.height);
    exit(0);
}



