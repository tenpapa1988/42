#ifndef MAPDATA_H
# define MAPDATA_H

# define MAX_SIZE 1000

// Define a struct to hold map data and its properties
typedef struct {
    char map[MAX_SIZE][MAX_SIZE];
    int rows;
    int cols;
    char chars[3]; // Holds empty, obstacle, and full characters
} MapData;

// Function prototypes
int read_map(const char *filename, MapData *map_data);
void find_largest_square(char map[MAX_SIZE][MAX_SIZE], int rows, int cols, char chars[3]);
void print_map(char map[MAX_SIZE][MAX_SIZE], int rows, int cols);

#endif // MAPDATA_H