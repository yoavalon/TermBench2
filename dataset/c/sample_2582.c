#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** initialize_grid(int size) {
    int** grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    return grid;
}

int** update_grid(int** grid, int size) {
    int** new_grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        new_grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            int neighbors = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;
                    neighbors += grid[(i + di + size) % size][(j + dj + size) % size];
                }
            }
            new_grid[i][j] = (neighbors == 3) || (grid[i][j] && neighbors == 2) ? 1 : 0;
        }
    }
    return new_grid;
}

int** simulate(int steps, int size) {
    int** grid = initialize_grid(size);
    for (int _ = 0; _ < steps; _++) {
        int** new_grid = update_grid(grid, size);
        for (int i = 0; i < size; i++) {
            free(grid[i]);
        }
        free(grid);
        grid = new_grid;
    }
    return grid;
}

void main() {
    srand(time(0));
    int steps = 10, size = 5;
    int** result = simulate(steps, size);
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
}