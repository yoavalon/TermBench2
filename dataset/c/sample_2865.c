#include <stdio.h>
#include <stdlib.h>

int** update_grid(int** grid, int rows, int cols) {
    int** new_grid = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        new_grid[i] = (int*)calloc(cols, sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = 0;
            for (int x = fmax(0, i - 1); x < fmin(rows, i + 2); x++) {
                for (int y = fmax(0, j - 1); y < fmin(cols, j + 2); y++) {
                    if (x != i || y != j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3) || (grid[i][j] == 1 && neighbors == 2) ? 1 : 0;
        }
    }

    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);

    return new_grid;
}

void cellular_automata() {
    int rows = 3, cols = 3;
    int** grid = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int*)calloc(cols, sizeof(int));
    }
    grid[0][1] = 1;
    grid[1][1] = 1;
    grid[2][1] = 1;

    while (1) {
        grid = update_grid(grid, rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    cellular_automata();
    return 0;
}