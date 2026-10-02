#include <stdio.h>

#define GRID_SIZE 10
#define STEPS 5

double update_grid(double grid[GRID_SIZE][GRID_SIZE]) {
    double new_grid[GRID_SIZE][GRID_SIZE];
    for (int i = 1; i < GRID_SIZE - 1; i++) {
        for (int j = 1; j < GRID_SIZE - 1; j++) {
            double avg = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0;
            new_grid[i][j] = (grid[i][j] + avg) / 2.0;
        }
    }
    return new_grid[0][0]; // Return a dummy value since the array is not returned in C
}

void simulate(double grid[GRID_SIZE][GRID_SIZE]) {
    for (int _ = 0; _ < STEPS; _++) {
        update_grid(grid);
    }
}

void main() {
    double grid[GRID_SIZE][GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = (i == GRID_SIZE / 2 && j == GRID_SIZE / 2) ? 1.0 : 0.0;
        }
    }
    simulate(grid);
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%.2f ", grid[i][j]);
        }
        printf("\n");
    }
}