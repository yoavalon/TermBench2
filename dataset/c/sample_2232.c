#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 100

void initialize_grid(int grid[GRID_SIZE][GRID_SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void evolve(int grid[GRID_SIZE][GRID_SIZE], int next_grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int neighbors = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = (i + di + GRID_SIZE) % GRID_SIZE;
                    int nj = (j + dj + GRID_SIZE) % GRID_SIZE;
                    neighbors += grid[ni][nj];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                next_grid[i][j] = 0;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                next_grid[i][j] = 1;
            } else {
                next_grid[i][j] = grid[i][j];
            }
        }
    }
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE];
    int next_grid[GRID_SIZE][GRID_SIZE];
    initialize_grid(grid);
    while (1) {
        evolve(grid, next_grid);
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                grid[i][j] = next_grid[i][j];
            }
        }
    }
    return 0;
}