#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

int update_grid(int grid[ROWS][COLS]) {
    int new_grid[ROWS][COLS] = {0};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0;
            for (int x = fmax(0, i - 1); x < fmin(ROWS, i + 2); x++) {
                for (int y = fmax(0, j - 1); y < fmin(COLS, j + 2); y++) {
                    if (x != i || y != j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            if (grid[i][j] && (neighbors == 2 || neighbors == 3) || (!grid[i][j] && neighbors == 3)) {
                new_grid[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
    return 0;
}

int main() {
    int grid[ROWS][COLS] = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    while (1) {
        update_grid(grid);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%c", grid[i][j] ? '█' : ' ');
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}