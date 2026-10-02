#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double** initialize_grid(int size) {
    double** grid = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        grid[i] = (double*)malloc(size * sizeof(double));
        for (int j = 0; j < size; j++) {
            grid[i][j] = (double)rand() / RAND_MAX;
        }
    }
    return grid;
}

double** evolve(double** grid, int size, int steps) {
    double** new_grid = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        new_grid[i] = (double*)malloc(size * sizeof(double));
    }
    for (int s = 0; s < steps; s++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                double sum = grid[(i + 1) % size][j] + grid[(i - 1 + size) % size][j] + grid[i][(j + 1) % size] + grid[i][(j - 1 + size) % size];
                new_grid[i][j] = sum > 1 ? 1 : sum;
            }
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
    for (int i = 0; i < size; i++) {
        free(new_grid[i]);
    }
    free(new_grid);
    return grid;
}

void main() {
    int size = 100;
    srand(time(0));
    double** grid = initialize_grid(size);
    while (1) {
        grid = evolve(grid, size, 10);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("%f ", grid[i][j]);
            }
            printf("\n");
        }
    }
    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);
}