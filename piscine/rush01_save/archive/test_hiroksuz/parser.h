#ifndef PARSER_H
#define PARSER_H

typedef struct {
    int col1up, col2up, col3up, col4up;
    int col1down, col2down, col3down, col4down;
    int row1left, row2left, row3left, row4left;
    int row1right, row2right, row3right, row4right;
} PuzzleData;

int parseInput(const char *input, PuzzleData *puzzleData);

#endif
