#include <stdio.h>

void update_grid(int grid[3][3], int new_grid[3][3]) {
    int rows = 3, cols = 3;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = 0;
            for (int x = (i > 0 ? i - 1 : 0); x < (i < rows - 1 ? i + 2 : rows); x++) {
                for (int y = (j > 0 ? j - 1 : 0); y < (j < cols - 1 ? j + 2 : cols); y++) {
                    if (x != i || y != j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3) ? 1 : (grid[i][j] && neighbors == 2);
        }
    }
}

void simulate(int grid[3][3]) {
    int new_grid[3][3];
    while (1) {
        update_grid(grid, new_grid);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
}

int main() {
    int initial_grid[3][3] = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    simulate(initial_grid);
    return 0;
}