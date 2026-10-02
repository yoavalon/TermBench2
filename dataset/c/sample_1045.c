#include <stdio.h>

int update_grid(int grid[][3], int new_grid[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = grid[(i - 1 + rows) % rows][(j - 1 + cols) % cols] + grid[(i - 1 + rows) % rows][j] + grid[(i - 1 + rows) % rows][(j + 1) % cols] + grid[i][(j - 1 + cols) % cols] + grid[i][(j + 1) % cols] + grid[(i + 1) % rows][(j - 1 + cols) % cols] + grid[(i + 1) % rows][j] + grid[(i + 1) % rows][(j + 1) % cols];
            new_grid[i][j] = neighbors / 2;
        }
    }
    return 0;
}

void simulate(int grid[][3], int rows, int cols) {
    int new_grid[3][3];
    while (1) {
        update_grid(grid, new_grid, rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", new_grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
}

int main() {
    int initial_grid[3][3] = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    simulate(initial_grid, 3, 3);
    return 0;
}