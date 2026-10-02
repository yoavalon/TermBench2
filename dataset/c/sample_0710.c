#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

int update_grid(int grid[ROWS][COLS]) {
    int new_grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0;
            for (int x = (i - 1 >= 0 ? i - 1 : 0); x < (i + 2 < ROWS ? i + 2 : ROWS); x++) {
                for (int y = (j - 1 >= 0 ? j - 1 : 0); y < (j + 2 < COLS ? j + 2 : COLS); y++) {
                    if (x != i || y != j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3 || (grid[i][j] && neighbors == 2)) ? 1 : 0;
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
    return 0;
}

void simulate(int grid[ROWS][COLS], int steps) {
    for (int _ = 0; _ < steps; _++) {
        update_grid(grid);
    }
}

void main() {
    int initial_grid[ROWS][COLS] = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    int steps = 5;
    simulate(initial_grid, steps);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", initial_grid[i][j]);
        }
        printf("\n");
    }
}