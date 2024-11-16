/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:19:34 by yussaito          #+#    #+#             */
/*   Updated: 2024/11/16 14:36:47 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "../libft/libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"

# define E_KEY_PRESS 2
# define E_WIN_RESIZE 9
# define E_WIN_CLOSE 17

# define M_KEY_PRESS 1
# define M_WIN_RESIZE 2097152
# define M_WIN_CLOSE 131072

# define IMAGE_SIZE 32

# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307

typedef enum e_bool
{
	FALSE,
	TRUE
} t_bool;

enum	e_components
{
	WALL,
	FLOOR,
	PLAYER,
	EXIT,
	COLLECTIBLE
};

typedef struct s_map
{
	char	**map;
	size_t	width;
	size_t	height;
	size_t	num_collectible;
	size_t	num_exit;
	size_t	num_s_position;
} t_map;

typedef struct s_img
{
	void	*img;
	int		img_width;
	int		img_height;
} t_img;

typedef struct  s_player
{
	size_t	x;
	size_t	y;
} t_player;

typedef struct  s_game
{
	t_map			map;
	void			*mlx;
	void			*mlx_win;
	t_img			img;
	t_player		player;
	unsigned int	move_count;
	const char		*assets_path[5];
	int				player_on_exit;
	char			floor_under_player;
} t_game;

int		open_if_file_is_valid(char *argv1);
void	free_all(t_game *game, char **map, size_t i);
void	error_exit(char *message);

void	get_map_data(int fd, t_game *game);
t_bool	is_map_valid(t_game *game);
void	dfs(t_game *game, char **map, int x, int y, t_bool **visited);
void	free_visited(t_bool **visited, size_t height);
void	free_and_exit(char *message, t_game *game, char **map_copy, size_t height);

size_t	map_row_len(const char *row);
t_bool	check_initial_row(t_list *map, t_game *game);
t_bool	check_middle_row(char *row, char *prev_row, char *next_row, t_game *game);
t_bool	check_middle_rows(t_list *map, t_game *game);
t_bool	check_final_row(t_list *map);

t_bool	check_map_dimensions(t_list *map, size_t width);
t_bool	check_edge_row(char *row);
t_bool	check_row_borders(char *row, size_t width);
t_bool	check_row_elements(char *row, t_game *game, size_t i);
t_bool	check_exit_surrounded(char *row, char *prev_row, char *next_row, size_t index);

int		ft_input(int key, void *game_);
int		close_window(t_game *game);
int		minimize_window(t_game *game);

void	init_assets_path(t_game *game);
void	ft_put_image_to_window(t_game *game, size_t x, size_t y);
void	select_image(t_game *game, char c);
void	get_image(t_game *game);
t_bool	can_move(t_game *game, char next_position);

#endif