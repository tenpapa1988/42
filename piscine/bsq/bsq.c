/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:42:54 by yussaito          #+#    #+#             */
/*   Updated: 2024/01/29 16:42:56 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "bsq.h"

// Declare function prototypes
char **read_map(const char *filename, t_map_info *map_info);
void find_largest_square(char **map, t_map_info map_info);
void free_map(char **map, int rows);

int main(int argc, char **argv) {
    t_map_info map_info;
    char **map;

    if (argc < 2) {
        // Handle standard input or show usage message
        printf("Usage: %s <map_file>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        map = read_map(argv[i], &map_info);
        if (!map) {
            // Handle error in map reading
            fprintf(stderr, "Map error\n");
            continue;
        }

        find_largest_square(map, map_info);

        // Print the map with the largest square marked
        for (int j = 0; j < map_info.rows; j++) {
            printf("%s\n", map[j]);
        }

        if (argc > 2 && i < argc - 1) {
            printf("\n");  // Separate multiple map outputs
        }

        free_map(map, map_info.rows);
    }

    return 0;
}

void free_map(char **map, int rows) {
    for (int i = 0; i < rows; i++) {
        free(map[i]);
    }
    free(map);
}
