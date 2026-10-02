#include <stdio.h>
#include <stdlib.h>

double** update_grid(double** grid, int width, int height) {
    double** new_grid = (double**)malloc(height * sizeof(double*));
    for (int i = 0; i < height; i++) {
        new_grid[i] = (double*)malloc(width * sizeof(double));
        for (int j = 0; j < width; j++) {
            double sum = 0.0;
            int count = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (dy != 0 || dx != 0) {
                        sum += grid[(i + dy + height) % height][(j + dx + width) % width];
                        count++;
                    }
                }
            }
            new_grid[i][j] = sum / count;
        }
    }
    return new_grid;
}

double** simulate(int width, int height, int steps) {
    double** grid = (double**)malloc(height * sizeof(double*));
    for (int i = 0; i < height; i++) {
        grid[i] = (double*)malloc(width * sizeof(double));
        for (int j = 0; j < width; j++) {
            grid[i][j] = (double)(i + j);
        }
    }
    for (int step = 0; step < steps; step++) {
        double** temp = update_grid(grid, width, height);
        for (int i = 0; i < height; i++) {
            free(grid[i]);
        }
        free(grid);
        grid = temp;
    }
    return grid;
}

void main() {
    int width = 10, height = 10, steps = 5;
    double** final_grid = simulate(width, height, steps);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%f ", final_grid[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < height; i++) {
        free(final_grid[i]);
    }
    free(final_grid);
}