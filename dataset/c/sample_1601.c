#include <stdio.h>

#define ROWS 3
#define COLS 3

void update_grid(int grid[ROWS][COLS], int new_grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0;
            for (int x = (i - 1 >= 0) ? i - 1 : 0; x < (i + 2 <= ROWS) ? i + 2 : ROWS; x++) {
                for (int y = (j - 1 >= 0) ? j - 1 : 0; y < (j + 2 <= COLS) ? j + 2 : COLS; y++) {
                    if ((x != i || y != j) && grid[x][y]) {
                        neighbors++;
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3 || (neighbors == 2 && grid[i][j])) ? 1 : 0;
        }
    }
}

void main() {
    int grid[ROWS][COLS] = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    int new_grid[ROWS][COLS];
    while (1) {
        update_grid(grid, new_grid);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%c ", grid[i][j] ? 'O' : '.');
            }
            printf("\n");
        }
        printf("\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
}