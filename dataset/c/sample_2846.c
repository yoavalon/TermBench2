#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate_grid(int size, int grid[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void update_grid(int size, int grid[size][size], int new_grid[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int neighbors = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    neighbors += grid[(i + dx + size) % size][(j + dy + size) % size];
                }
            }
            if ((grid[i][j] && (neighbors == 2 || neighbors == 3)) || (!grid[i][j] && neighbors == 3)) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = 0;
            }
        }
    }
}

void main() {
    int size = 10;
    int grid[size][size];
    int new_grid[size][size];
    srand(time(NULL));
    generate_grid(size, grid);
    while (1) {
        update_grid(size, grid, new_grid);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
}