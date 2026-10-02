#include <stdio.h>

void initialize_grid(int grid[50][50], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = 0;
        }
    }
}

void update_grid(int grid[50][50], int rows, int cols) {
    int new_grid[50][50];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            new_grid[i][j] = grid[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = 0;
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < rows && y >= 0 && y < cols && !(x == i && y == j)) {
                        neighbors += grid[x][y];
                    }
                }
            }
            if (neighbors == 3) {
                new_grid[i][j] = 1;
            } else if (neighbors < 2 || neighbors > 3) {
                new_grid[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    int rows = 50, cols = 50;
    int grid[50][50];
    initialize_grid(grid, rows, cols);
    while (1) {
        update_grid(grid, rows, cols);
    }
    return 0;
}