#include <stdio.h>
#include <stdlib.h>

void update_state(double** grid, int rows, int cols) {
    double** new_grid = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        new_grid[i] = (double*)malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            double value = 0.0;
            int count = 0;
            int neighbors[4][2] = {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};
            for (int k = 0; k < 4; k++) {
                int x = neighbors[k][0];
                int y = neighbors[k][1];
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    value += grid[x][y];
                    count++;
                }
            }
            new_grid[i][j] = value / (count * 1.0);
        }
    }
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
    grid = new_grid;
}

void simulate(double** grid, int rows, int cols) {
    while (1) {
        update_state(grid, rows, cols);
    }
}

int main() {
    int grid_size = 10;
    double** initial_grid = (double**)malloc(grid_size * sizeof(double*));
    for (int i = 0; i < grid_size; i++) {
        initial_grid[i] = (double*)malloc(grid_size * sizeof(double));
        for (int j = 0; j < grid_size; j++) {
            initial_grid[i][j] = (double)(i * j);
        }
    }
    simulate(initial_grid, grid_size, grid_size);
    return 0;
}