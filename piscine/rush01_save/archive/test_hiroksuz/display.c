#include "display.h"
#include <stdio.h>

// 4x4のグリッドにおける箱の配置を表示する関数
void printGrid(const int grid[4][4]) {
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}
