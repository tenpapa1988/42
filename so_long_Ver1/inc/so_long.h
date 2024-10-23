/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:19:34 by yussaito          #+#    #+#             */
/*   Updated: 2024/10/23 08:54:54 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_h
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "../libft/libft/libft.h"
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
	t_map		map;
	void		*mlx;
	void		*mlx_win;
	t_img		img;
	t_player	player;
	size_t		move_count;
} t_game;

#endif