#include <stdio.h>

#define ROWS 3
#define COLS 3

void update_grid(int grid[ROWS][COLS], int new_grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < ROWS && nj >= 0 && nj < COLS) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            if (grid[i][j] == 1) {
                new_grid[i][j] = (neighbors >= 2 && neighbors <= 3) ? 1 : 0;
            } else {
                new_grid[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
    }
}

void main() {
    int initial_grid[ROWS][COLS] = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    for (int _ = 0; _ < 10; _++) {
        int new_grid[ROWS][COLS];
        update_grid(initial_grid, new_grid);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%c", new_grid[i][j] ? '#' : ' ');
            }
            printf("\n");
        }
        printf("\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                initial_grid[i][j] = new_grid[i][j];
            }
        }
    }
}