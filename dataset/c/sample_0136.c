#include <stdio.h>
#include <stdlib.h>

int initialize_grid(int size, int **grid) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }
    return 0;
}

int update_grid(int size, int **grid, int **new_grid) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int neighbors = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < size && nj >= 0 && nj < size) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            if (grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    return 0;
}

int main() {
    int grid_size = 50;
    int iterations = 100;
    int **grid = (int **)malloc(grid_size * sizeof(int *));
    int **new_grid = (int **)malloc(grid_size * sizeof(int *));
    for (int i = 0; i < grid_size; i++) {
        grid[i] = (int *)malloc(grid_size * sizeof(int));
        new_grid[i] = (int *)malloc(grid_size * sizeof(int));
    }

    initialize_grid(grid_size, grid);
    for (int _ = 0; _ < iterations; _++) {
        update_grid(grid_size, grid, new_grid);
        for (int i = 0; i < grid_size; i++) {
            for (int j = 0; j < grid_size; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }

    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < grid_size; i++) {
        free(grid[i]);
        free(new_grid[i]);
    }
    free(grid);
    free(new_grid);

    return 0;
}