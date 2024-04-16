#include "solver.h"
#include <stdbool.h>

// solve関数のプロトタイプ宣言
bool solve(PuzzleData *puzzleData, int grid[4][4], int row, int col);

// 行に同じ数字がないかをチェックする関数
bool isRowValid(const int grid[4][4], int row, int num) {
    for (int col = 0; col < 4; col++) {
        if (grid[row][col] == num) {
            return false;
        }
    }
    return true;
}

// 列に同じ数字がないかをチェックする関数
bool isColValid(const int grid[4][4], int col, int num) {
    for (int row = 0; row < 4; row++) {
        if (grid[row][col] == num) {
            return false;
        }
    }
    return true;
}

// 視点からの制約をチェックする関数
bool isViewValid(const PuzzleData *puzzleData, const int grid[4][4], int row, int col, int num) {
    (void)puzzleData; // 未使用パラメータを明示的に無視
    (void)grid;
    (void)row;
    (void)col;
    (void)num;

    // ここに視点からの制約チェックのロジックを実装
    return true; // 仮実装
}

// 制約を満たしているかをチェックする関数
bool isValid(const PuzzleData *puzzleData, const int grid[4][4], int row, int col, int num) {
    return isRowValid(grid, row, num) && isColValid(grid, col, num) && isViewValid(puzzleData, grid, row, col, num);
}

// バックトラックアルゴリズムを使用してパズルを解く関数
bool solvePuzzle(PuzzleData *puzzleData, int grid[4][4]) {
    // 4x4のグリッドを0で初期化
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j] = 0;
        }
    }

    return solve(puzzleData, grid, 0, 0); // 初期位置から解を探す
}

// 実際にバックトラックアルゴリズムを実行する関数
bool solve(PuzzleData *puzzleData, int grid[4][4], int row, int col) {
    // すべてのマスを埋めたら成功
    if (row == 4) {
        return true;
    }

    // 次のマスに進む
    int nextRow = (col == 3) ? row + 1 : row;
    int nextCol = (col == 3) ? 0 : col + 1;

    // すでに数字がある場合は次へ進む
    if (grid[row][col] != 0) {
        return solve(puzzleData, grid, nextRow, nextCol);
    }

    // このマスに1から4の数字を試す
    for (int num = 1; num <= 4; num++) {
        if (isValid(puzzleData, grid, row, col, num)) {
            grid[row][col] = num;

            if (solve(puzzleData, grid, nextRow, nextCol)) {
                return true; // 成功した場合
            }

            grid[row][col] = 0; // バックトラック
        }
    }

    return false; // 解が見つからない
}
