#include <stdio.h>
#include <stdlib.h>

int** simulate_cells(int rows, int cols, int steps) {
    int** grid = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int*)calloc(cols, sizeof(int));
    }

    for (int t = 0; t < steps; t++) {
        int** new_grid = (int**)malloc(rows * sizeof(int*));
        for (int i = 0; i < rows; i++) {
            new_grid[i] = (int*)calloc(cols, sizeof(int));
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbors = 0;
                for (int x = (i > 0 ? i - 1 : 0); x <= (i < rows - 1 ? i + 1 : rows - 1); x++) {
                    for (int y = (j > 0 ? j - 1 : 0); y <= (j < cols - 1 ? j + 1 : cols - 1); y++) {
                        if (x != i || y != j) {
                            neighbors += grid[x][y];
                        }
                    }
                }
                if (neighbors == 3 || (grid[i][j] && neighbors == 2)) {
                    new_grid[i][j] = 1;
                }
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
    int rows = 10, cols = 10, steps = 5;
    int** result = simulate_cells(rows, cols, steps);

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