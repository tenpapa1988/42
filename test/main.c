/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yussaito <yussaito@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:44:02 by yussaito          #+#    #+#             */
/*   Updated: 2024/05/23 14:33:56 by yussaito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
    int line_count = 0;
    while ((line = get_next_line(fd)) != NULL) {
        printf("Line %d: %s", line_count++, line);
        free(line); // get_next_lineから返されたメモリを解放
    }

    // ここでEOFに達したことをチェックし、適切なメッセージを表示
    if (line == NULL && line_count > 0) {
        printf("End of file reached after %d lines.\n", line_count);
    } else if (line_count == 0) {
        printf("The file is empty.\n");
    }

    close(fd); // ファイルディスクリプタをクローズ
    return 0;
}