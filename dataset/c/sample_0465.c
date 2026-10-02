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
    grid[size / 2][size / 2] = 1;
    return grid;
}

int** update_grid(int** grid) {
    int** new_grid = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; i++) {
        new_grid[i] = (int*)malloc(SIZE * sizeof(int));
        for (int j = 0; j < SIZE; j++) {
            int neighbors = 0;
            for (int x = fmax(0, i - 1); x < fmin(SIZE, i + 2); x++) {
                for (int y = fmax(0, j - 1); y < fmin(SIZE, j + 2); y++) {
                    if (x != i || y != j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            if (neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = 0;
            }
        }
    }
    return new_grid;
}

void main() {
    int** grid = initialize_grid(SIZE);
    while (1) {
        grid = update_grid(grid);
    }
}