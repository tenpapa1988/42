/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 08:56:54 by yussaito          #+#    #+#             */
/*   Updated: 2024/05/13 08:59:56 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd) {
    if (fd < 0) {
        return NULL;
    }

    char *line = malloc(1024 * sizeof(char));  // Allocate initial buffer
    if (!line) {
        return NULL;  // Return NULL if malloc failed
    }

    int i = 0, n;
    char buff;
    while ((n = read(fd, &buff, 1)) > 0) {
        if (buff == '\n') {
            break;  // Stop at newline
        }
        line[i++] = buff;
        if (i >= 1024) {  // Check if we need more space
            char *new_line = realloc(line, (i + 1024) * sizeof(char));
            if (!new_line) {
                free(line);
                return NULL;  // Return NULL if realloc failed
            }
            line = new_line;
        }
    }

    if (n <= 0 && i == 0) {  // No data read or error occurred
        free(line);
        return NULL;
    }

    line[i] = '\0';  // Null-terminate the string
    return line;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY); // 第一引数で指定されたファイルを読み取り専用でオープン
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line); // get_next_lineから返されたメモリを解放
    }

    close(fd); // ファイルディスクリプタをクローズ
    return 0;
}
