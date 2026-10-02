#include <stdio.h>

void simulate() {
    int grid[50][50] = {0};
    while (1) {
        int new_grid[50][50] = {0};
        for (int i = 1; i < 49; i++) {
            for (int j = 1; j < 49; j++) {
                int neighbors = grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1];
                new_grid[i][j] = (neighbors == 2) ? 1 : 0;
            }
        }
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
}

int main() {
    simulate();
    return 0;
}