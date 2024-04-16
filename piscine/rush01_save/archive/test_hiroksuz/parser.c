#include "parser.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 文字列を整数に変換し、エラーチェックを行う関数
int parseNumber(const char *str) {
    char *endptr;
    long val = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0' || val < 1 || val > 4) {
        return -1; // 変換エラー
    }

    return (int)val;
}

// コマンドライン引数から視点データを解析する関数
int parseInput(const char *input, PuzzleData *puzzleData) {
    const int expectedNumValues = 16; // 期待される値の数
    int values[expectedNumValues];
    char *token;
    char inputCopy[256]; // 入力のコピーを保存
    int count = 0;

    strncpy(inputCopy, input, sizeof(inputCopy));
    inputCopy[sizeof(inputCopy) - 1] = '\0'; // セーフティ

    token = strtok(inputCopy, " ");
    while (token != NULL) {
        int num = parseNumber(token);
        if (num == -1) {
            return 0; // 解析エラー
        }

        values[count++] = num;
        token = strtok(NULL, " ");

        if (count > expectedNumValues) {
            return 0; // 余分な値がある
        }
    }

    if (count != expectedNumValues) {
        return 0; // 値が足りない
    }

    // 解析された値を構造体に割り当てる
    puzzleData->col1up = values[0];
    puzzleData->col2up = values[1];
    // ... 各値を割り当てる ...

    return 1; // 成功
}
