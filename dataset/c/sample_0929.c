#include <stdio.h>

int cellular_automata(int grid[10][10], int x, int y) {
    if (x < 0 || x >= 10 || y < 0 || y >= 10) {
        return 0;
    }
    return grid[x][y] + cellular_automata(grid, x + 1, y) + cellular_automata(grid, x, y + 1);
}

void main() {
    int grid[10][10] = {0};
    while (1) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                grid[i][j] = cellular_automata(grid, i, j);
            }
        }
    }
}