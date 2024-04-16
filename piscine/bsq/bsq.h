/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:43:01 by yussaito          #+#    #+#             */
/*   Updated: 2024/01/29 16:56:38 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
#define BSQ_H

// Structure to hold map information
typedef struct s_map_info {
    int rows;           // Number of rows in the map
    int cols;           // Number of columns in the map
    char empty;         // Character representing empty space
    char obstacle;      // Character representing an obstacle
    char full;          // Character representing the part of the square
} t_map_info;

// Structure to hold information about the largest square found
typedef struct s_square {
    int row;            // Starting row of the square
    int col;            // Starting column of the square
    int size;           // Size of the square
} t_square;

// Function prototypes
char **read_map(const char *filename, t_map_info *map_info);
void find_largest_square(char **map, t_map_info map_info);
void free_map(char **map, int rows);
int get_map_info(int fd, t_map_info *map_info);

#endif // BSQ_H