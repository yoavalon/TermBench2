#include <stdio.h>

int update_grid(int grid[10][10], int size, int new_grid[10][10]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int neighbors = 0;
            for (int x = (i > 0 ? i - 1 : 0); x < (i < size - 1 ? i + 2 : size); x++) {
                for (int y = (j > 0 ? j - 1 : 0); y < (j < size - 1 ? j + 2 : size); y++) {
                    if (x != i || y != j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3 || (neighbors == 2 && grid[i][j])) ? 1 : 0;
        }
    }
    return 0;
}

void simulate(int grid[10][10], int size, int steps, int new_grid[10][10]) {
    if (steps == 0) {
        return;
    }
    update_grid(grid, size, new_grid);
    simulate(new_grid, size, steps - 1, grid);
}

void main() {
    int size = 10;
    int initial_grid[10][10] = {0};
    int final_grid[10][10] = {0};
    initial_grid[5][5] = 1;
    initial_grid[5][6] = 1;
    initial_grid[6][5] = 1;
    initial_grid[6][6] = 1;
    simulate(initial_grid, size, 10, final_grid);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", final_grid[i][j]);
        }
        printf("\n");
    }
}