#include <stdio.h>

#define ROWS 3
#define COLS 3

int update_state(int grid[ROWS][COLS]) {
    int new_grid[ROWS][COLS];
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            int neighbors = 0;
            if (r > 0) neighbors += grid[r - 1][c];
            if (r < ROWS - 1) neighbors += grid[r + 1][c];
            if (c > 0) neighbors += grid[r][c - 1];
            if (c < COLS - 1) neighbors += grid[r][c + 1];
            new_grid[r][c] = (neighbors == 3) ? 1 : grid[r][c];
        }
    }
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            grid[r][c] = new_grid[r][c];
        }
    }
    return 0;
}

void run_simulation() {
    int grid[ROWS][COLS] = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    while (1) {
        update_state(grid);
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                printf("%c", (grid[r][c] ? 'O' : ' '));
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    run_simulation();
    return 0;
}