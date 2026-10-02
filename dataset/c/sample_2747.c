#include <stdio.h>

void cellular_automata(int x, int y, int steps) {
    int grid[y][x];
    int new_grid[y][x];
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            grid[i][j] = 0;
        }
    }
    for (int step = 0; step < steps; step++) {
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                new_grid[i][j] = grid[i][j];
            }
        }
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                int neighbors = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (i + di >= 0 && i + di < y && j + dj >= 0 && j + dj < x) {
                            neighbors += grid[i + di][j + dj];
                        }
                    }
                }
                neighbors -= grid[i][j];
                new_grid[i][j] = (neighbors == 3) || (neighbors == 2 && grid[i][j]) ? 1 : 0;
            }
        }
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
}

int main() {
    cellular_automata(10, 10, 1000000);
    return 0;
}