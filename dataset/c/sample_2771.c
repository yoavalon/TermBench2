#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 30

void simulate() {
    int grid[GRID_SIZE][GRID_SIZE] = {0};
    while (1) {
        int new_grid[GRID_SIZE][GRID_SIZE] = {0};
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                int neighbors = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (x == 0 && y == 0) continue;
                        neighbors += grid[(i + x + GRID_SIZE) % GRID_SIZE][(j + y + GRID_SIZE) % GRID_SIZE];
                    }
                }
                if ((grid[i][j] && (neighbors == 2 || neighbors == 3)) || (!grid[i][j] && neighbors == 3)) {
                    new_grid[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
}

int main() {
    simulate();
    return 0;
}