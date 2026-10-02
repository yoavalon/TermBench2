#include <stdio.h>
#include <stdlib.h>

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

int** update_grid(int** grid, int size) {
    int** new_grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        new_grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            int neighbors = 0;
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < size && y >= 0 && y < size && !(x == i && y == j)) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3) ? 1 : 0;
        }
    }
    return new_grid;
}

void free_grid(int** grid, int size) {
    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);
}

void main() {
    int size = 50;
    int** grid = initialize_grid(size);
    while (1) {
        int** new_grid = update_grid(grid, size);
        free_grid(grid, size);
        grid = new_grid;
    }
}