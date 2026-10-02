#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

int update_grid(int grid[ROWS][COLS], int rules[512]) {
    int new_grid[ROWS][COLS] = {0};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors[8];
            int count = 0;
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < ROWS && y >= 0 && y < COLS && !(x == i && y == j)) {
                        neighbors[count++] = grid[x][y];
                    }
                }
            }
            int key = 0;
            for (int k = 0; k < count; k++) {
                key = (key << 1) | neighbors[k];
            }
            new_grid[i][j] = rules[key];
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
    int grid[ROWS][COLS] = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
    int rules[512] = {0};
    rules[255] = 1;
    rules[240] = 1;
    while (1) {
        update_grid(grid, rules);
    }
    return 0;
}