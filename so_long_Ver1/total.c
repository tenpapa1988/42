#include "../inc/so_long.h"


const char	*g_assets_path[5] = {
	"assets/wall/wall.xpm",
	"assets/floor/floor.xpm",
	"assets/player/player.xpm",
	"assets/exit/exit.xpm",
	"assets/sprite/sprite.xpm",
};

void	ft_put_image_to_window(t_game *game, size_t x, size_t y)
{
	x *= IMAGE_SIZE;
	y *= IMAGE_SIZE;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, x, y);
}

void	select_image(t_game *game, char c)
{
	char	*path;

	if (c == '1')
		path = (char *)g_assets_path[WALL];
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
	game->img.img = mlx_xpm_file_to_image(game->mlx, path,
		&game->img.img_height, &game->img.img_width);
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
			mlx_destroy_image(game->mlx, game->img.img);
			if (game->map.map[y][x] == 'P')
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
	if (next_position == 'E')
	{
		if (game->map.num_collectible == 0)
			mlx_loop_end(game->mlx);
		return (FALSE);
	}
	if (next_position != '1')
	{
		game->move_count += 1;
		ft_printf("move count-> %u\n", game->move_count);
		return (TRUE);	
	}
	return (FALSE);
}



void	error_exit_with_lstclear(t_list *map, char *message)
{
	ft_lstclear(&map, free);
	error_exit(message);
}

void	move_list_to_double_pointer(t_game *game, t_list *map)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	game->map.map = (char **)ft_calloc(game->map.height + 1, sizeof(char *));
	if (game->map.map == NULL)
		error_exit_with_lstclear(map, "failed malloc");
	tmp = map;
	while (i < game->map.height)
	{
		game->map.map[i] = ft_strdup(tmp->content);
		if (!game->map.map[i])
			error_exit_with_lstclear(map, "faild malloc for map row");
		tmp = tmp->next;
		i++;
	}
	ft_lstclear(&map, free);
}


static t_bool check_map_dimensions(t_list *map, size_t width)
{
    while (map) {
        if (!map->content || map_row_len(map->content) != width)
            return (FALSE);
        map = map->next;
    }
    return (TRUE);
}

// Check if a row is valid based on its position (edge row)
static t_bool check_edge_row(char *row)
{
    while (*row) {
        if (*row != '1' && *row != '\n')
		return (FALSE);
        row++;
    }
    return (TRUE);
}

// Check if the middle rows follow the specified rules
static t_bool check_middle_row(char *row, char *prev_row, char *next_row, t_game *game)
{
	size_t	i;

	i = 0;
    if (row[0] != '1' || row[game->map.width - 1] != '1')
        return (FALSE);
    while (row[i])
	{
        if (ft_strchr("10CPE\n", row[i]) == NULL)
            return (FALSE);
        if (row[i] == 'C')
            game->map.num_collectible++;
        if (row[i] == 'P')
		{
            game->map.num_s_position++;
            if (game->map.num_s_position > 1)
                return (FALSE);
        }
        if (row[i] == 'E')
		{
            game->map.num_exit++;
            if (game->map.num_exit > 1)
                return (FALSE);
            if (is_exit_surrounded_by_walls(row, prev_row, next_row, i))
                return (FALSE);
        }
        i++;
    }
    return (TRUE);
}


// Check if 'E' is fully surrounded by walls ('1's)
static t_bool is_exit_surrounded_by_walls(char *row, char *prev_row, char *next_row, size_t index)
{
    if (!prev_row || !next_row)
        return (FALSE);
    return (prev_row[index] == '1' && next_row[index] == '1' &&
            row[index - 1] == '1' && row[index + 1] == '1');
}

// Validate that necessary elements exist (C, P, E)
static t_bool validate_map_elements(t_game *game)
{
    return (game->map.num_collectible > 0 && game->map.num_exit == 1
            && game->map.num_s_position == 1);
}

// Main map validation function
static t_bool check_initial_row(t_list *map, t_game *game)
{
    if (!map || !map->content)
        return (FALSE);
    game->map.width = map_row_len(map->content);
    if (!map->next || !check_map_dimensions(map, game->map.width) || !check_edge_row(map->content))
        return (FALSE);
    return (TRUE);
}

// Check middle rows
static t_bool check_middle_rows(t_list *map, t_game *game)
{
    char *prev_row;
    char *next_row;

    if (!map || !map->content)
        return (FALSE);
    prev_row = map->content;
    while (map && map->next)
	{
        next_row = map->next->content;
        if (!check_middle_row(map->content, prev_row, next_row, game))
            return (FALSE);
        prev_row = map->content;
        map = map->next;
    }
    return (TRUE);
}

// Check the final row (edge row)
static t_bool check_final_row(t_list *map)
{
    if (!map || !map->content)
        return (FALSE);
    if (!check_edge_row(map->content))
        return (FALSE);
    return (TRUE);
}

// Main map validation function
static t_bool get_map_info(t_list *map, t_game *game)
{
    if (!map || !check_initial_row(map, game))
        return (FALSE);
    map = map->next;
    if (map && !check_middle_rows(map, game))
        return (FALSE);
    while (map && map->next)
        map = map->next;
    if (!check_final_row(map))
        return (FALSE);
    if (!validate_map_elements(game))
	{
		return (FALSE);
	}
	return (TRUE);
}

// Check the first row (edge row)
static size_t map_row_len(const char *row)
{
	size_t	i;

	i = 0;
    if (!row)
		return (0);
    while (*row)
	{
        if (ft_strchr("10CPE", *row))
            i++;
        row++;
    }
    return (i);
}

void get_map_data(int fd, t_game *game)
{
    t_list  *current;
    t_list  head;
    char    *line;

    game->map.height = 0;
    errno = 0;
    head.next = NULL;
    current = &head;
    while ((line = get_next_line(fd)) != NULL)
    {
        current->next = ft_lstnew(line);
        if (!current->next) {
            free(line);
            error_exit_with_lstclear(head.next, "Failed to allocate memory for list node");
        }
        current = current->next;
        game->map.height++;
    }
    if (head.next == NULL || head.next->content == NULL || get_map_info(head.next, game) == FALSE)
        error_exit_with_lstclear(head.next, "invalid map");
    move_list_to_double_pointer(game, head.next);
}



static int	ft_update(void *game_, size_t x, size_t y)
{
	t_game	*game;

	game = (t_game *)game_;
	if (x != game->player.x || y != game->player.y)
		select_image(game, 'P');
	else
		return (0);
	ft_put_image_to_window(game, game->player.x, game->player.y);
	mlx_destroy_image(game->mlx, game->img.img);
	select_image(game, '0');
	ft_put_image_to_window(game, x, y);
	mlx_destroy_image(game->mlx, game->img.img);
	game->map.map[y][x] = '0';
	x = game->player.x;
	y = game->player.y;
	if (game->map.map[y][x] == 'C')
	{
		game->map.num_collectible -= 1;
	}
	game->map.map[y][x] = 'P';
	return (0);
}

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

	game = (t_game *)game_;
	x = game->player.x;
	y = game->player.y;
	if (key == ESC)
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

void	free_all(t_game game, char **map, size_t i)
{
	while (i > 0)
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

	argv1_len = ft_strlen(argv1);
	if(argv1_len < 4 || ft_strncmp(argv1 + argv1_len - 4, ".ber", 5))
		error_exit("invalid extension");
	fd = open(argv1, O_RDONLY);
	if (fd == -1)
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
	game = (t_game){0};
	get_map_data(fd, &game);
	close(fd);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		error_exit(strerror(errno));
	game.mlx_win = mlx_new_window(game.mlx, game.map.width * IMAGE_SIZE, game.map.height * IMAGE_SIZE, argv[0]);
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
