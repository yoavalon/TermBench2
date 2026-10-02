#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define STEPS 50

int** init_grid(int size) {
    int** grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }
    grid[size / 2][size / 2] = 1;
    return grid;
}

int** update_grid(int** grid, int size) {
    int** new_grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        new_grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            new_grid[i][j] = grid[i][j];
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int neighbors = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < size && nj >= 0 && nj < size) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);

    return new_grid;
}

void print_grid(int** grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int** grid = init_grid(SIZE);
    for (int step = 0; step < STEPS; step++) {
        grid = update_grid(grid, SIZE);
    }
    print_grid(grid, SIZE);

    for (int i = 0; i < SIZE; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}