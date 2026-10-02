#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 10

int update_grid(int grid[GRID_SIZE][GRID_SIZE]) {
    int new_grid[GRID_SIZE][GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int neighbors = 0;
            for (int x = (i > 0 ? i - 1 : 0); x <= (i < GRID_SIZE - 1 ? i + 1 : GRID_SIZE - 1); x++) {
                for (int y = (j > 0 ? j - 1 : 0); y <= (j < GRID_SIZE - 1 ? j + 1 : GRID_SIZE - 1); y++) {
                    if (x != i || y != j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3) || (grid[i][j] && neighbors == 2);
        }
    }
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
    return 0;
}

void simulate(int grid[GRID_SIZE][GRID_SIZE]) {
    while (1) {
        update_grid(grid);
    }
}

void main() {
    int initial_grid[GRID_SIZE][GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            initial_grid[i][j] = (i % 2 == 0 || j % 2 == 0) ? 0 : 1;
        }
    }
    simulate(initial_grid);
}