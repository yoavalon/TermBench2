#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10

void update_grid(int grid[GRID_SIZE][GRID_SIZE]) {
    int rows = GRID_SIZE;
    int cols = GRID_SIZE;
    int new_grid[GRID_SIZE][GRID_SIZE];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = grid[i][(j - 1 + cols) % cols] + grid[i][(j + 1) % cols] + grid[(i - 1 + rows) % rows][j] + grid[(i + 1) % rows][j] + grid[(i - 1 + rows) % rows][(j - 1 + cols) % cols] + grid[(i - 1 + rows) % rows][(j + 1) % cols] + grid[(i + 1) % rows][(j - 1 + cols) % cols] + grid[(i + 1) % rows][(j + 1) % cols];
            if (grid[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                }
            } else if (neighbors == 3) {
                new_grid[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

void main() {
    srand(time(NULL));
    int grid[GRID_SIZE][GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    while (1) {
        update_grid(grid);
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        printf("--------------------\n");
    }
}