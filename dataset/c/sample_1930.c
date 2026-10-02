#include <stdio.h>
#include <stdlib.h>

void update_grid(double **grid, double **new_grid, int size, int precision) {
    for (int i = 1; i < size - 1; i++) {
        for (int j = 1; j < size - 1; j++) {
            double sum = 0.0;
            for (int k = i - 1; k <= i + 1; k++) {
                for (int l = j - 1; l <= j + 1; l++) {
                    sum += grid[k][l];
                }
            }
            double avg = sum / 9.0;
            new_grid[i][j] = (double)lround(avg * pow(10, precision)) / pow(10, precision);
        }
    }
}

void run_simulation(int steps, int precision) {
    int grid_size = 10;
    double **grid = (double **)malloc(grid_size * sizeof(double *));
    double **new_grid = (double **)malloc(grid_size * sizeof(double *));
    for (int i = 0; i < grid_size; i++) {
        grid[i] = (double *)malloc(grid_size * sizeof(double));
        new_grid[i] = (double *)malloc(grid_size * sizeof(double));
        for (int j = 0; j < grid_size; j++) {
            grid[i][j] = ((double)rand() / RAND_MAX);
            new_grid[i][j] = 0.0;
        }
    }
    for (int step = 0; step < steps; step++) {
        update_grid(grid, new_grid, grid_size, precision);
        for (int i = 0; i < grid_size; i++) {
            for (int j = 0; j < grid_size; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            printf("%f ", grid[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < grid_size; i++) {
        free(grid[i]);
        free(new_grid[i]);
    }
    free(grid);
    free(new_grid);
}

int main() {
    int steps = 50;
    int precision = 3;
    run_simulation(steps, precision);
    return 0;
}