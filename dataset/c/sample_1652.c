#include <stdio.h>

void update_grid(int grid[5][5]) {
    int rows = 5, cols = 5;
    int new_grid[5][5] = {0};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = 0;
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < rows && y >= 0 && y < cols && (x != i || y != j)) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3) || (neighbors == 2 && grid[i][j] == 1) ? 1 : 0;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

void simulate(int grid[5][5]) {
    while (1) {
        update_grid(grid);
    }
}

void main() {
    int initial_grid[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    simulate(initial_grid);
}