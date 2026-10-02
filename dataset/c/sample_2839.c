#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void update_grid(int grid[SIZE][SIZE]) {
    int new_grid[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int neighbors = 0;
            for (int ni = -1; ni <= 1; ni++) {
                for (int nj = -1; nj <= 1; nj++) {
                    int ii = i + ni, jj = j + nj;
                    if (ii >= 0 && ii < SIZE && jj >= 0 && jj < SIZE) {
                        neighbors += grid[ii][jj];
                    }
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    int grid[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    while (1) {
        update_grid(grid);
    }
    return 0;
}