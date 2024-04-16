/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:43:23 by yussaito          #+#    #+#             */
/*   Updated: 2024/01/29 17:28:02 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "bsq.h"

char **allocate_map(int rows, int cols);
int get_map_info(int fd, t_map_info *map_info);

char **read_map(const char *filename, t_map_info *map_info) {
    int fd;
    char **map;
    int i;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return NULL;
    }

    if (!get_map_info(fd, map_info)) {
        close(fd);
        return NULL;
    }

    map = allocate_map(map_info->rows, map_info->cols);
    if (!map) {
        close(fd);
        return NULL;
    }

    for (i = 0; i < map_info->rows; i++) {
        if (read(fd, map[i], map_info->cols) != map_info->cols || map[i][map_info->cols - 1] != '\n') {
            // Handle error or free allocated memory
            close(fd);
            free_map(map, i);
            return NULL;
        }
    }

    close(fd);
    return map;
}

char **allocate_map(int rows, int cols) {
    char **map = malloc(rows * sizeof(char *));
    if (!map) return NULL;

    for (int i = 0; i < rows; i++) {
        map[i] = malloc(cols * sizeof(char));
        if (!map[i]) {
            // Free previously allocated memory
            free_map(map, i);
            return NULL;
        }
    }
    return map;
}
