#include <stdio.h>

void update_grid(double grid[5][5], double new_grid[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i > 0 && j > 0 && i < 4 && j < 4) {
                new_grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
}

void simulate(int n, int size, double grid[5][5]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = (double)(i == size / 2 && j == size / 2);
        }
    }
    for (int _ = 0; _ < n; _++) {
        double new_grid[5][5];
        update_grid(grid, new_grid);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
}

void main() {
    double result[5][5];
    simulate(10, 5, result);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%f ", result[i][j]);
        }
        printf("\n");
    }
}