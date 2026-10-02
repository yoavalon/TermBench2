#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** initialize_grid(int size) {
    srand(time(NULL));
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
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < size && y >= 0 && y < size && !(x == i && y == j)) {
                        neighbors += grid[x][y];
                    }
                }
            }
            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    return new_grid;
}

void free_grid(int** grid, int size) {
    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);
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
    int size = 5;
    int** grid = initialize_grid(size);
    for (int _ = 0; _ < 10; _++) {
        int** new_grid = update_grid(grid, size);
        free_grid(grid, size);
        grid = new_grid;
    }
    print_grid(grid, size);
    free_grid(grid, size);
    return 0;
}