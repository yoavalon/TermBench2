#include <stdio.h>

#define ROWS 10
#define COLS 10

void update_grid(double grid[ROWS][COLS], double new_grid[ROWS][COLS]) {
    int rows = ROWS;
    int cols = COLS;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double total = 0.0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        total += grid[ni][nj];
                    }
                }
            }
            new_grid[i][j] = total / 9.0;
        }
    }
}

void simulate() {
    double grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = i + j;
        }
    }
    double new_grid[ROWS][COLS];
    while (1) {
        update_grid(grid, new_grid);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
}

int main() {
    simulate();
    return 0;
}