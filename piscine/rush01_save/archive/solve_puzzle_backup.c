#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4

int countVisible(int arr[], int size, int step) {
    int max_height = 0;
    int visible_count = 0;
    int i = (step == 1) ? 0 : size - 1;
    while (i >= 0 && i < size) {
        if (arr[i] > max_height) {
            visible_count++;
            max_height = arr[i];
        }
        i += step;
    }
    return visible_count;
}

int checkVisibility(int grid[SIZE][SIZE], int views[]) {
    int row[SIZE], col[SIZE];

    for (int i = 0; i < SIZE; i++) {
        // Extract the row and column
        for (int j = 0; j < SIZE; j++) {
            row[j] = grid[i][j];
            col[j] = grid[j][i];
        }

        // Check row visibility from left and right
        if (countVisible(row, SIZE, 1) != views[8 + i] || countVisible(row, SIZE, -1) != views[12 + i])
            return 0;

        // Check column visibility from top and bottom
        if (countVisible(col, SIZE, 1) != views[i] || countVisible(col, SIZE, -1) != views[4 + i])
            return 0;
    }

    return 1;
}

int isValid(int grid[SIZE][SIZE], int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num)
            return 0;
    }
    return 1;
}

int solvePuzzle(int grid[SIZE][SIZE], int row, int col, int views[16]) {
    if (row == SIZE) {
        return checkVisibility(grid, views);
    }
    if (col == SIZE) {
        return solvePuzzle(grid, row + 1, 0, views);
    }

    for (int num = 1; num <= SIZE; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solvePuzzle(grid, row, col + 1, views))
                return 1;
            grid[row][col] = 0; // Backtrack
        }
    }

    return 0;
}

void printGrid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int parseViews(char *input, int views[16]) {
    char *token = strtok(input, " ");
    for (int i = 0; token != NULL && i < 16; i++) {
        views[i] = atoi(token);
        token = strtok(NULL, " ");
    }
    return (token == NULL) ? 1 : 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Error\n");
        return 1;
    }

    int views[16];
    if (!parseViews(argv[1], views)) {
        printf("Error\n");
        return 1;
    }

    int grid[SIZE][SIZE] = {0};
    if (solvePuzzle(grid, 0, 0, views)) {
        printGrid(grid);
    } else {
        printf("Error\n");
    }

    return 0;
}
