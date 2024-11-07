/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:44:01 by yussaito          #+#    #+#             */
/*   Updated: 2024/11/07 10:46:55 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// static t_bool	check_middle_row(char *row, size_t width, t_game *game)
// {
// 	if (row[0] != '1' || row[width - 1] != '1')
// 		return(FALSE);
// 	while (*row)
// 	{
// 		if (ft_strchr("10CPE\n", *row) == NULL)
// 			return (FALSE);
// 		if (*row == 'C')
// 			game->map.num_collectible += 1;
// 		if (*row == 'P')
// 		{
// 			game->map.num_s_position += 1;
// 			if (game->map.num_s_position > 1)
// 				return (FALSE);
// 		}
// 		if (*row == 'E')
// 		{
// 			game->map.num_exit += 1;
// 			if (game->map.num_exit > 1)
// 				return (FALSE);
// 		}
// 		row++;
// 	}
// 	return (TRUE);
// }

// static t_bool	check_edge_row(char *row)
// {
// 	while(*row)
// 	{
// 		if (*row != '1' && *row != '\n')
// 			return (FALSE);
// 		row++;
// 	}
// 	return (TRUE);
// }

// static size_t	map_row_len(const char *row)
// {
// 	size_t	i;

// 	i = 0;
// 	while (*row != '\0')
// 	{
// 		if (ft_strchr("10CPE", *row))
// 			i++;
// 		row++;
// 	}
// 	return (i);
// }

// static t_bool	get_map_info(t_list *map, t_game *game)
// {
// 	size_t	i;

// 	i = 0;
// 	game->map.width = map_row_len(map->content);
// 	while (map->content != NULL)
// 	{
// 		if (i != 0 && game->map.width != map_row_len(map->content))
// 			return (FALSE);
// 		if (i == 0 || i + 1 == game->map.height)
// 		{
// 			if (check_edge_row(map->content) == FALSE)
// 				return (FALSE);
// 		}
// 		else
// 		{
// 			if (check_middle_row(map->content, game->map.width, game) == FALSE)
// 				return (FALSE);
// 		}
// 		i++;
// 		map = map->next;
// 	}
// 	if (!game->map.num_collectible || !game->map.num_exit
// 		|| !game->map.num_s_position)
// 		return (FALSE);
// 	return (TRUE);
// }

#include <stdio.h>

static size_t map_row_len(const char *row);
static t_bool is_exit_surrounded_by_walls(char *row, char *prev_row, char *next_row, size_t index);

// Check if all rows have the same width
static t_bool check_map_dimensions(t_list *map, size_t width) {
    while (map) {
        if (!map->content || map_row_len(map->content) != width) {
            printf("Width mismatch: expected %zu, got %zu\n", width, map_row_len(map->content)); // デバッグ出力
            return (FALSE);
        }
        map = map->next;
    }
    return (TRUE);
}

// Check if a row is valid based on its position (edge row)
static t_bool check_edge_row(char *row) {
    while (*row) {
        if (*row != '1' && *row != '\n') {
            printf("Edge row check failed at character: %c\n", *row); // デバッグ出力
            return (FALSE);
        }
        row++;
    }
    return (TRUE);
}

// Check if the middle rows follow the specified rules
static t_bool check_middle_row(char *row, char *prev_row, char *next_row, t_game *game)
{
    if (row[0] != '1' || row[game->map.width - 1] != '1')
        return (FALSE);

    size_t i = 0;
    while (row[i]) {
        if (ft_strchr("10CPE\n", row[i]) == NULL)
            return (FALSE);
        
        if (row[i] == 'C') {
            game->map.num_collectible++;
            printf("Collectible found, total: %zu\n", game->map.num_collectible); // デバッグ出力
        }
        
        if (row[i] == 'P') {
            game->map.num_s_position++;
            printf("Player position found, total: %zu\n", game->map.num_s_position); // デバッグ出力
            if (game->map.num_s_position > 1)
                return (FALSE);
        }
        
        if (row[i] == 'E') {
            game->map.num_exit++;
            printf("Exit found, total: %zu\n", game->map.num_exit); // デバッグ出力
            if (game->map.num_exit > 1)
                return (FALSE);
            
            // Check if 'E' is fully surrounded by '1's
            if (is_exit_surrounded_by_walls(row, prev_row, next_row, i))
                return (FALSE);
        }
        
        i++;
    }
    return (TRUE);
}


// Check if 'E' is fully surrounded by walls ('1's)
static t_bool is_exit_surrounded_by_walls(char *row, char *prev_row, char *next_row, size_t index) {
    if (!prev_row || !next_row)
        return (FALSE);
    return (prev_row[index] == '1' && next_row[index] == '1' &&
            row[index - 1] == '1' && row[index + 1] == '1');
}

// Validate that necessary elements exist (C, P, E)
static t_bool validate_map_elements(t_game *game) {
    printf("Validating map elements: Collectibles=%zu, Exits=%zu, Start Positions=%zu\n",
           game->map.num_collectible, game->map.num_exit, game->map.num_s_position); // デバッグ出力
    return (game->map.num_collectible > 0 && game->map.num_exit == 1
            && game->map.num_s_position == 1);
}

// Main map validation function
static t_bool check_initial_row(t_list *map, t_game *game)
{
    if (!map || !map->content) {
        printf("Error: map or map->content is NULL in check_initial_row.\n");
        return (FALSE);
    }

    game->map.width = map_row_len(map->content);
    printf("Checking initial row, width: %zu\n", game->map.width);

    if (!map->next || !check_map_dimensions(map, game->map.width) || !check_edge_row(map->content)) {
        printf("Initial row check failed in width or edge row validation.\n");
        return (FALSE);
    }
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
    printf("Checking middle rows...\n"); // デバッグ出力

    while (map && map->next) {
        next_row = map->next->content;
        if (!check_middle_row(map->content, prev_row, next_row, game)) {
            printf("Middle row check failed.\n"); // デバッグ出力
            return (FALSE);
        }
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

    printf("Checking final row...\n"); // デバッグ出力

    if (!check_edge_row(map->content)) {
        printf("Final row check failed in edge row validation.\n"); // デバッグ出力
        return (FALSE);
    }
    return (TRUE);
}

// Main map validation function
// Main map validation function
static t_bool get_map_info(t_list *map, t_game *game)
{
    printf("Starting map validation...\n"); // デバッグ出力

    if (!map || !check_initial_row(map, game)) {
        printf("Initial row check failed.\n"); // デバッグ出力
        return (FALSE);
    }

    map = map->next;
    if (map && !check_middle_rows(map, game)) {
        printf("Middle rows check failed.\n"); // デバッグ出力
        return (FALSE);
    }

    while (map && map->next)
        map = map->next;

    if (!check_final_row(map)) {
        printf("Final row check failed.\n"); // デバッグ出力
        return (FALSE);
    }

    if (!validate_map_elements(game)) {
        printf("Required elements check failed.\n"); // デバッグ出力
        return (FALSE);
    }

    printf("Map validation succeeded.\n"); // デバッグ出力
    return (TRUE);
}

// Check the first row (edge row)
static size_t map_row_len(const char *row) {
    if (!row) {
        printf("Error: NULL pointer passed to map_row_len.\n"); // デバッグ出力
        return 0;
    }

    size_t i = 0;
    while (*row) {
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

    if (head.next == NULL || head.next->content == NULL || get_map_info(head.next, game) == FALSE) {
        printf("Error in get_map_data: Invalid map or failed to initialize map.\n"); // デバッグ出力
        error_exit_with_lstclear(head.next, "invalid map");
    }

    move_list_to_double_pointer(game, head.next);
}

