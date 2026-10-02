#include <stdio.h>

void cellular_automata() {
    int grid[3][3] = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    while (1) {
        int new_grid[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int live_neighbors = 0;
                for (int x = i - 1; x < i + 2; x++) {
                    for (int y = j - 1; y < j + 2; y++) {
                        if ((0 <= x && x < 3 && 0 <= y && y < 3) && (x != i || y != j) && grid[x][y]) {
                            live_neighbors++;
                        }
                    }
                }
                new_grid[i][j] = (live_neighbors == 2) ? 1 : 0;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
}

int main() {
    cellular_automata();
    return 0;
}