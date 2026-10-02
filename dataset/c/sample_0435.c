#include <stdio.h>

#define GRID_SIZE 3

int update_grid(int grid[GRID_SIZE][GRID_SIZE], int (*rule)(int*, int)) {
    int new_grid[GRID_SIZE][GRID_SIZE] = {0};
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int neighbors[8];
            int count = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (!(di == 0 && dj == 0)) {
                        neighbors[count++] = grid[(i + di + GRID_SIZE) % GRID_SIZE][(j + dj + GRID_SIZE) % GRID_SIZE];
                    }
                }
            }
            new_grid[i][j] = rule(neighbors, grid[i][j]);
        }
    }
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
    return 0;
}

int evolve(int grid[GRID_SIZE][GRID_SIZE], int (*rule)(int*, int), int steps) {
    for (int _ = 0; _ < steps; _++) {
        update_grid(grid, rule);
    }
    return 0;
}

int rule(int neighbors[8], int cell) {
    int sum = 0;
    for (int i = 0; i < 8; i++) {
        sum += neighbors[i];
    }
    return sum == 3 ? 1 : 0;
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE] = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    while (1) {
        evolve(grid, rule, 1);
    }
    return 0;
}