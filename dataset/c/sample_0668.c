#include <stdio.h>

int cellular_automata(int grid[5][5], int steps) {
    if (steps == 0) {
        return 1;
    }
    int new_grid[5][5] = {0};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int neighbors = 0;
            if (i > 0) neighbors += grid[i - 1][j];
            if (i < 4) neighbors += grid[i + 1][j];
            if (j > 0) neighbors += grid[i][j - 1];
            if (j < 4) neighbors += grid[i][j + 1];
            new_grid[i][j] = (neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)) ? 1 : 0;
        }
    }
    return cellular_automata(new_grid, steps - 1);
}

int main() {
    int grid[5][5] = {{0, 0, 0, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}};
    cellular_automata(grid, 10);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}