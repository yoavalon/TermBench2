#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int** init_grid(int size) {
    int** grid = (int**)malloc(size * sizeof(int*));
    for (int y = 0; y < size; y++) {
        grid[y] = (int*)malloc(size * sizeof(int));
        for (int x = 0; x < size; x++) {
            grid[y][x] = (x != 0 && x != size - 1 && y != 0 && y != size - 1) ? 0 : 1;
        }
    }
    return grid;
}

int** update_grid(int** grid, int size) {
    int** new_grid = (int**)malloc(size * sizeof(int*));
    for (int y = 0; y < size; y++) {
        new_grid[y] = (int*)malloc(size * sizeof(int));
    }
    for (int y = 1; y < size - 1; y++) {
        for (int x = 1; x < size - 1; x++) {
            int neighbors = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (dy != 0 || dx != 0) {
                        neighbors += grid[y + dy][x + dx];
                    }
                }
            }
            new_grid[y][x] = (neighbors >= 2) ? 1 : 0;
        }
    }
    for (int y = 0; y < size; y++) {
        free(grid[y]);
    }
    free(grid);
    return new_grid;
}

void simulate(int** grid, int size) {
    while (1) {
        grid = update_grid(grid, size);
    }
}

int main() {
    int size = SIZE;
    int** grid = init_grid(size);
    simulate(grid, size);
    return 0;
}