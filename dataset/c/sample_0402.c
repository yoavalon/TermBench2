#include <stdio.h>

#define ROWS 3
#define COLS 3

int update_cells(int grid[ROWS][COLS]) {
    int new_grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0;
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < ROWS && y >= 0 && y < COLS && !(x == i && y == j)) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3) ? 1 : grid[i][j];
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
    return 0;
}

void display_grid(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", (grid[i][j] == 1) ? 'O' : '.');
        }
        printf("\n");
    }
}

int main() {
    int grid[ROWS][COLS] = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    while (1) {
        display_grid(grid);
        update_cells(grid);
    }
    return 0;
}