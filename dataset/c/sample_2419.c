#include <stdio.h>
#include <stdlib.h>

int** cellular_automata(int** grid, int rows, int cols, int steps) {
    for (int _ = 0; _ < steps; _++) {
        int** new_grid = (int**)malloc(rows * sizeof(int*));
        for (int i = 0; i < rows; i++) {
            new_grid[i] = (int*)malloc(cols * sizeof(int));
            for (int j = 0; j < cols; j++) {
                int neighbors = 0;
                if (i > 0) neighbors += grid[i - 1][j];
                if (i < rows - 1) neighbors += grid[i + 1][j];
                if (j > 0) neighbors += grid[i][j - 1];
                if (j < cols - 1) neighbors += grid[i][j + 1];
                new_grid[i][j] = (neighbors == 2 || (neighbors == 3 && grid[i][j] == 1)) ? 1 : 0;
            }
        }
        for (int i = 0; i < rows; i++) {
            free(grid[i]);
        }
        free(grid);
        grid = new_grid;
    }
    return grid;
}

int main() {
    int initial_grid[3][3] = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    int rows = 3, cols = 3, steps = 5;
    int** result = cellular_automata((int**)initial_grid, rows, cols, steps);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < rows; i++) {
        free(result[i]);
    }
    free(result);
    return 0;
}