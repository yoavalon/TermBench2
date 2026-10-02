#include <stdio.h>
#include <stdlib.h>

int** update_grid(int** grid, int rows, int cols) {
    int** new_grid = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        new_grid[i] = (int*)calloc(cols, sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int count = 0;
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < rows && y >= 0 && y < cols && !(x == i && y == j)) {
                        count += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (grid[i][j] && (count == 2 || count == 3)) || count == 3;
        }
    }
    return new_grid;
}

int** simulate(int** grid, int steps, int rows, int cols) {
    for (int _ = 0; _ < steps; _++) {
        grid = update_grid(grid, rows, cols);
    }
    return grid;
}

void main() {
    int initial_grid[5][5] = {{0, 0, 0, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}};
    int** final_grid = simulate((int**)initial_grid, 10, 5, 5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", final_grid[i][j]);
        }
        printf("\n");
    }
}