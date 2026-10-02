#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

float** update_grid(float** grid) {
    float** new_grid = (float**)malloc(ROWS * sizeof(float*));
    for (int i = 0; i < ROWS; i++) {
        new_grid[i] = (float*)malloc(COLS * sizeof(float));
    }
    for (int i = 1; i < ROWS - 1; i++) {
        for (int j = 1; j < COLS - 1; j++) {
            float sum = 0.0;
            for (int ni = -1; ni <= 1; ni++) {
                for (int nj = -1; nj <= 1; nj++) {
                    sum += grid[i + ni][j + nj];
                }
            }
            new_grid[i][j] = sum - grid[i][j];
        }
    }
    return new_grid;
}

float** simulate_flow(int iterations) {
    float** grid = (float**)malloc(ROWS * sizeof(float*));
    for (int i = 0; i < ROWS; i++) {
        grid[i] = (float*)malloc(COLS * sizeof(float));
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = ((float)rand() / RAND_MAX);
        }
    }
    for (int iter = 0; iter < iterations; iter++) {
        float** temp = update_grid(grid);
        for (int i = 0; i < ROWS; i++) {
            free(grid[i]);
        }
        free(grid);
        grid = temp;
    }
    return grid;
}

void print_grid(float** grid) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%f ", grid[i][j]);
        }
        printf("\n");
    }
}

void main() {
    float** result = simulate_flow(100);
    print_grid(result);
    for (int i = 0; i < ROWS; i++) {
        free(result[i]);
    }
    free(result);
}