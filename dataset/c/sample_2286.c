#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 50

void update_grid(int grid[GRID_SIZE][GRID_SIZE], int new_grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 1; i < GRID_SIZE - 1; i++) {
        for (int j = 1; j < GRID_SIZE - 1; j++) {
            int neighbors = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    neighbors += grid[i + di][j + dj];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] == 1) {
                new_grid[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            } else {
                new_grid[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
    }
}

void main() {
    int grid[GRID_SIZE][GRID_SIZE];
    int new_grid[GRID_SIZE][GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    while (1) {
        update_grid(grid, new_grid);
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
}