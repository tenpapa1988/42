#include <stdio.h>
#include "parser.h"
#include "solver.h"
#include "display.h"

int main(int argc, char *argv[]) {
    // コマンドライン引数の確認
    if (argc != 2) {
        fprintf(stderr, "Usage: %s \"puzzle_input\"\n", argv[0]);
        return 1;
    }

    // 引数を解析
    PuzzleData puzzleData;
    if (!parseInput(argv[1], &puzzleData)) {
        fprintf(stderr, "Error: Invalid input format.\n");
        return 1;
    }

    int grid[4][4] = {{0}};
    if (solvePuzzle(&puzzleData, grid)) {
        printGrid(grid); // 解決策を出力
    } else {
        fprintf(stderr, "Error: No solution found.\n");
    }

    return 0;
}
