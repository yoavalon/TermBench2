#include <stdio.h>

void cellular_automata(int rows, int cols, int steps) {
    int grid[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = 0;
        }
    }
    for (int step = 0; step < steps; step++) {
        int new_grid[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbors = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx != 0 || dy != 0) {
                            neighbors += grid[(i + dx + rows) % rows][(j + dy + cols) % cols];
                        }
                    }
                }
                new_grid[i][j] = (neighbors == 3) ? 1 : grid[i][j];
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
}

void main() {
    while (1) {
        cellular_automata(10, 10, 100);
    }
}