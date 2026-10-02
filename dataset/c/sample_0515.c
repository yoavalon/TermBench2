#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

int initialize_grid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    return 0;
}

int update_grid(int grid[SIZE][SIZE], int new_grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int neighbors = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue;
                    int ni = (i + x + SIZE) % SIZE;
                    int nj = (j + y + SIZE) % SIZE;
                    neighbors += grid[ni][nj];
                }
            }
            if (grid[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                new_grid[i][j] = 1;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = 0;
            }
        }
    }
    return 0;
}

int main() {
    int grid[SIZE][SIZE];
    int new_grid[SIZE][SIZE];
    srand(time(NULL));
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