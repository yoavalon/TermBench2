#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** update_grid(int** grid, int size) {
    int** new_grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        new_grid[i] = (int*)calloc(size, sizeof(int));
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int neighbors[] = {grid[(i - 1 + size) % size][(j - 1 + size) % size], grid[(i - 1 + size) % size][j], grid[(i - 1 + size) % size][(j + 1) % size], grid[i][(j - 1 + size) % size], grid[i][(j + 1) % size], grid[(i + 1) % size][(j - 1 + size) % size], grid[(i + 1) % size][j], grid[(i + 1) % size][(j + 1) % size]};
            int live_neighbors = 0;
            for (int k = 0; k < 8; k++) {
                live_neighbors += neighbors[k];
            }
            if (grid[i][j]) {
                new_grid[i][j] = (live_neighbors == 2 || live_neighbors == 3) ? 1 : 0;
            } else {
                new_grid[i][j] = (live_neighbors == 3) ? 1 : 0;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);
    return new_grid;
}

int main() {
    srand(time(NULL));
    int size = 10;
    int** grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    while (1) {
        grid = update_grid(grid, size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}