#include <stdio.h>

double** init_grid(int size) {
    double** grid = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        grid[i] = (double*)malloc(size * sizeof(double));
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0.0;
        }
    }
    return grid;
}

double** update_grid(double** grid, int size, double diffusion_rate) {
    double** new_grid = init_grid(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            double neighbors = 0.0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < size && nj >= 0 && nj < size) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            new_grid[i][j] = grid[i][j] + diffusion_rate * neighbors;
        }
    }
    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);
    return new_grid;
}

int main() {
    int size = 100;
    double diffusion_rate = 0.01;
    double** grid = init_grid(size);
    while (1) {
        grid = update_grid(grid, size, diffusion_rate);
    }
    return 0;
}