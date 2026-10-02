#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int** initialize_grid(int size) {
    int** grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }
    return grid;
}

int** update_grid(int** grid) {
    int** new_grid = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; i++) {
        new_grid[i] = (int*)malloc(SIZE * sizeof(int));
        for (int j = 0; j < SIZE; j++) {
            int neighbors = 0;
            for (int x = -1; x < 2; x++) {
                for (int y = -1; y < 2; y++) {
                    if (x == 0 && y == 0) continue;
                    int ni = i + x, nj = j + y;
                    if (ni >= 0 && ni < SIZE && nj >= 0 && nj < SIZE) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3) ? 1 : 0;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        free(grid[i]);
    }
    free(grid);
    return new_grid;
}

void main() {
    int** grid = initialize_grid(SIZE);
    while (1) {
        grid = update_grid(grid);
    }
}