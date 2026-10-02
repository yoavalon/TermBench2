#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

void update_grid(int grid[SIZE][SIZE], int new_grid[SIZE][SIZE]) {
    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            int neighbors_sum = 0;
            for (int ni = -1; ni <= 1; ni++) {
                for (int nj = -1; nj <= 1; nj++) {
                    if (ni == 0 && nj == 0) continue;
                    neighbors_sum += grid[i + ni][j + nj];
                }
            }
            if (grid[i][j] == 0 && neighbors_sum > 2) {
                new_grid[i][j] = 1;
            } else if (grid[i][j] == 1 && (neighbors_sum < 2 || neighbors_sum > 3)) {
                new_grid[i][j] = 0;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
}

int main() {
    int grid[SIZE][SIZE];
    int new_grid[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
            new_grid[i][j] = 0;
        }
    }
    grid[SIZE / 2][SIZE / 2] = 1;
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