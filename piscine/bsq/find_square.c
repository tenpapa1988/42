/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fins_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:43:08 by yussaito          #+#    #+#             */
/*   Updated: 2024/01/29 16:43:09 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

void update_square_info(t_square *max_square, int row, int col, int size);
int min(int a, int b, int c);

void find_largest_square(char **map, t_map_info map_info) {
    int **dp;
    t_square max_square = {0, 0, 0}; // Initialize max square info
    int i, j;

    // Allocate memory for the dynamic programming array
    dp = (int **)malloc(map_info.rows * sizeof(int *));
    for (i = 0; i < map_info.rows; i++) {
        dp[i] = (int *)malloc(map_info.cols * sizeof(int));
    }

    // Fill the dynamic programming array
    for (i = 0; i < map_info.rows; i++) {
        for (j = 0; j < map_info.cols; j++) {
            if (map[i][j] == map_info.obstacle) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = 1;
                if (i > 0 && j > 0) {
                    dp[i][j] += min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
                }
                if (dp[i][j] > max_square.size) {
                    update_square_info(&max_square, i, j, dp[i][j]);
                }
            }
        }
    }

    // Mark the largest square on the map
    for (i = max_square.row; i > max_square.row - max_square.size; i--) {
        for (j = max_square.col; j > max_square.col - max_square.size; j--) {
            map[i][j] = map_info.full;
        }
    }

    // Free the dynamic programming array
    for (i = 0; i < map_info.rows; i++) {
        free(dp[i]);
    }
    free(dp);
}

void update_square_info(t_square *max_square, int row, int col, int size) {
    max_square->row = row;
    max_square->col = col;
    max_square->size = size;
}

int min(int a, int b, int c) {
    if (a < b) return (a < c) ? a : c;
    else return (b < c) ? b : c;
}