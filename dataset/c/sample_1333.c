#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50
#define STEPS 100

void update_grid(int grid[SIZE][SIZE]) {
    int new_grid[SIZE][SIZE];
    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            int neighbors = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue;
                    neighbors += grid[i + x][j + y];
                }
            }
            if (grid[i][j] && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (!grid[i][j] && neighbors == 3) {
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

void simulate(int grid[SIZE][SIZE], int steps) {
    for (int _ = 0; _ < steps; _++) {
        update_grid(grid);
    }
}

void main() {
    int grid[SIZE][SIZE];
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
        }
    }
    for (int i = 20; i < 25; i++) {
        for (int j = 20; j < 25; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    simulate(grid, STEPS);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}