#include <stdio.h>
#include <stdlib.h>

int** init_grid(int rows, int cols) {
    int** grid = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            grid[i][j] = 0;
        }
    }
    grid[rows / 2][cols / 2] = 1;
    return grid;
}

int** update_grid(int** grid, int rows, int cols) {
    int** new_grid = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        new_grid[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            int neighbors = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    int x = i + dx;
                    int y = j + dy;
                    if (x >= 0 && x < rows && y >= 0 && y < cols) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 1) ? 1 : 0;
        }
    }
    return new_grid;
}

void free_grid(int** grid, int rows) {
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}

int main() {
    int rows = 10;
    int cols = 10;
    int** grid = init_grid(rows, cols);
    while (1) {
        int** new_grid = update_grid(grid, rows, cols);
        free_grid(grid, rows);
        grid = new_grid;
    }
    return 0;
}