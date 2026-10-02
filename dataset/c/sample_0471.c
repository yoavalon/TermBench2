#include <stdio.h>

#define SIZE 10

void initialize_grid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
        }
    }
    grid[SIZE / 2][SIZE / 2] = 1;
}

void update_grid(int grid[SIZE][SIZE], int new_grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int neighbors = 0;
            for (int x = (i - 1 >= 0) ? i - 1 : 0; x < (i + 2 < SIZE) ? i + 2 : SIZE; x++) {
                for (int y = (j - 1 >= 0) ? j - 1 : 0; y < (j + 2 < SIZE) ? j + 2 : SIZE; y++) {
                    neighbors += grid[x][y];
                }
            }
            if (neighbors == 3 || (grid[i][j] && neighbors == 2)) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = 0;
            }
        }
    }
}

int main() {
    int grid[SIZE][SIZE];
    int new_grid[SIZE][SIZE];
    initialize_grid(grid);
    while (1) {
        update_grid(grid, new_grid);
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
    return 0;
}