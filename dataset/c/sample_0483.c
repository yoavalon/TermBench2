#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void update_grid(int grid[ROWS][COLS], int new_grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x != 0 || y != 0) {
                        int nx = i + x;
                        int ny = j + y;
                        if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS) {
                            neighbors += grid[nx][ny];
                        }
                    }
                }
            }
            if (grid[i][j]) {
                new_grid[i][j] = (neighbors >= 2 && neighbors <= 3) ? 1 : 0;
            } else {
                new_grid[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
    }
}

void simulate(int grid[ROWS][COLS]) {
    while (1) {
        int new_grid[ROWS][COLS];
        update_grid(grid, new_grid);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
}

int main() {
    int initial_grid[ROWS][COLS] = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    simulate(initial_grid);
    return 0;
}