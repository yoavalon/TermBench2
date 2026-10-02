#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void update_state(int grid[ROWS][COLS], int new_grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0;
            for (int x = fmax(0, i - 1); x < fmin(i + 2, ROWS); x++) {
                for (int y = fmax(0, j - 1); y < fmin(j + 2, COLS); y++) {
                    if (x != i || y != j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3) ? 1 : (neighbors < 2 || neighbors > 3) ? 0 : grid[i][j];
        }
    }
}

void main() {
    int grid[ROWS][COLS] = {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};
    int new_grid[ROWS][COLS];

    while (1) {
        update_state(grid, new_grid);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%d ", new_grid[i][j]);
            }
            printf("\n");
        }
        for (int j = 0; j < COLS; j++) {
            printf("--");
        }
        printf("\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
}