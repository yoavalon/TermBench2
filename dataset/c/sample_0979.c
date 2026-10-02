#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void fluid_dynamics(int grid[SIZE][SIZE]) {
    int next_grid[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int neighbors = 0;
            for (int x = fmax(0, i - 1); x < fmin(SIZE, i + 2); x++) {
                for (int y = fmax(0, j - 1); y < fmin(SIZE, j + 2); y++) {
                    neighbors += grid[x][y];
                }
            }
            next_grid[i][j] = (neighbors > 4) ? 1 : 0;
        }
    }
    fluid_dynamics(next_grid);
}

int main() {
    int grid[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
        }
    }
    grid[5][5] = 1;
    fluid_dynamics(grid);
    return 0;
}