#include <stdio.h>
#include <stdlib.h>

int** update_grid(int** grid, int size) {
    int** new_grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        new_grid[i] = (int*)calloc(size, sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int neighbors = 0;
            for (int x = fmax(0, i - 1); x < fmin(size, i + 2); x++) {
                for (int y = fmax(0, j - 1); y < fmin(size, j + 2); y++) {
                    if (x != i || y != j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3) ? 1 : (neighbors == 2) ? grid[i][j] : 0;
        }
    }

    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);

    return new_grid;
}

int** simulate(int size, int steps) {
    int** grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            grid[i][j] = (i % 2) ? 0 : 1;
        }
    }

    for (int step = 0; step < steps; step++) {
        grid = update_grid(grid, size);
    }

    return grid;
}

int main() {
    int size = 5;
    int steps = 10;
    int** result = simulate(size, steps);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}