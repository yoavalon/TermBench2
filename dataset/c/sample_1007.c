#include <stdio.h>

#define ROWS 3
#define COLS 3

void update_grid(int grid[ROWS][COLS]) {
    int new_grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0;
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < ROWS && y >= 0 && y < COLS && (x != i || y != j)) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (neighbors >= 2 && neighbors <= 3) || (grid[i][j] == 0 && neighbors == 3) ? 1 : 0;
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

void run_simulation(int grid[ROWS][COLS]) {
    while (1) {
        update_grid(grid);
    }
}

int main() {
    int initial_grid[ROWS][COLS] = {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};
    run_simulation(initial_grid);
    return 0;
}