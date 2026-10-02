#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

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

int** update_grid(int** grid, int size) {
    int** new_grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        new_grid[i] = (int*)malloc(size * sizeof(int));
    }
    for (int i = 1; i < size - 1; i++) {
        for (int j = 1; j < size - 1; j++) {
            int neighbors = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    neighbors += grid[i + x][j + y];
                }
            }
            neighbors -= grid[i][j];
            if (neighbors == 3 || (grid[i][j] && neighbors == 2)) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = 0;
            }
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

int main() {
    int size = SIZE;
    int** grid = initialize_grid(size);
    while (1) {
        int** new_grid = update_grid(grid, size);
        free_grid(grid, size);
        grid = new_grid;
    }
    return 0;
}