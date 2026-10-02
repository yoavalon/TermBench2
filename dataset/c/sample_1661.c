#include <stdio.h>
#include <stdlib.h>

int update_grid(int **grid, int rows, int cols) {
    int **new_grid = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        new_grid[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            int neighbors = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue;
                    int ni = i + x;
                    int nj = j + y;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3 || (grid[i][j] && neighbors == 2)) ? 1 : 0;
        }
    }
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
    return (int **)new_grid;
}

void main() {
    int rows = 3;
    int cols = 3;
    int **initial_grid = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        initial_grid[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            initial_grid[i][j] = (i == 1) ? 1 : 0;
        }
    }
    while (1) {
        initial_grid = update_grid(initial_grid, rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d", initial_grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}