#include <stdio.h>

void cellular_automata() {
    int grid[10][10] = {0};
    while (1) {
        for (int i = 1; i < 9; i++) {
            for (int j = 1; j < 9; j++) {
                grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) % 2;
            }
        }
        for (int i = 0; i < 10; i++) {
            grid[i][0] = grid[i][9];
            grid[i][9] = grid[i][0];
            grid[0][i] = grid[9][i];
            grid[9][i] = grid[0][i];
        }
    }
}

int main() {
    cellular_automata();
    return 0;
}