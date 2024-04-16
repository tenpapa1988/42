/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:56:57 by yussaito          #+#    #+#             */
/*   Updated: 2024/01/29 17:22:15 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>
#include <stdlib.h>

int get_map_info(int fd, t_map_info *map_info) {
    char buf[1024]; // Assuming first line will not exceed 1024 characters
    int bytes_read = 0;
    int i;

    // Read the first line
    bytes_read = read(fd, buf, 1024);
    for (i = 0; i < bytes_read; i++) {
        if (buf[i] == '\n') {
            buf[i] = '\0';
            break;
        }
    }
    if (i == bytes_read) { // Newline not found
        return 0;
    }

    // Extract number of rows and characters
    int num_length = 0;
    while (buf[num_length] >= '0' && buf[num_length] <= '9') {
        num_length++;
    }
    if (num_length == 0 || i - num_length != 3) { // No digits or not exactly 3 characters following
        return 0;
    }

    char num_buf[1024];
    for (int j = 0; j < num_length; j++) {
        num_buf[j] = buf[j];
    }
    num_buf[num_length] = '\0';

    map_info->rows = atoi(num_buf);
    map_info->empty = buf[num_length];
    map_info->obstacle = buf[num_length + 1];
    map_info->full = buf[num_length + 2];

    // Basic validation
    if (map_info->empty == map_info->obstacle || map_info->empty == map_info->full || map_info->obstacle == map_info->full) {
        return 0;
    }

    return 1; // Return 1 if successful
}
