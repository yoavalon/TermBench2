#include <stdio.h>
#include <stdbool.h>

bool update_cell(int grid[][10], int i, int j, int size) {
    int neighbors = 0;
    for (int x = i - 1; x < i + 2; x++) {
        for (int y = j - 1; y < j + 2; y++) {
            if (0 <= x && x < size && 0 <= y && y < size && (x != i || y != j)) {
                neighbors += grid[x][y];
            }
        }
    }
    return neighbors == 3 || (grid[i][j] && neighbors == 2);
}

void step(int grid[][10], int new_grid[][10], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            new_grid[i][j] = update_cell(grid, i, j, size);
        }
    }
}

void main() {
    int size = 10;
    int grid[10][10] = {0};
    int new_grid[10][10] = {0};
    grid[1][1] = 1;
    grid[2][2] = 1;
    grid[2][1] = 1;
    while (1) {
        step(grid, new_grid, size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
}