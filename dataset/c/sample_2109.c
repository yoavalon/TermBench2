#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void simulate() {
    double grid[100][100];
    double new_grid[100][100];

    // Initialize grid with random values
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            grid[i][j] = (double)rand() / RAND_MAX;
        }
    }

    while (1) {
        for (int i = 1; i < 99; i++) {
            for (int j = 1; j < 99; j++) {
                new_grid[i][j] = 0.25 * (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]);
            }
        }

        // Copy new_grid to grid
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
}

int main() {
    srand(time(NULL));
    simulate();
    return 0;
}