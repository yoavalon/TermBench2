#include <stdio.h>

void cellular_automata(int n) {
    int grid[n][n];
    int next_grid[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = 0;
        }
    }
    while (1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                next_grid[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int neighbors = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (x == 0 && y == 0) continue;
                        neighbors += grid[(i + x + n) % n][(j + y + n) % n];
                    }
                }
                if (neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)) {
                    next_grid[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = next_grid[i][j];
            }
        }
    }
}

int main() {
    cellular_automata(10);
    return 0;
}