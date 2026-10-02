#include <stdio.h>

int update_cell(int state, int neighbors[], int num_neighbors) {
    int active_neighbors = 0;
    for (int i = 0; i < num_neighbors; i++) {
        active_neighbors += neighbors[i];
    }
    if (state == 1) {
        return active_neighbors == 2 || active_neighbors == 3 ? 1 : 0;
    } else {
        return active_neighbors == 3 ? 1 : 0;
    }
}

void simulate(int grid[5][5]) {
    int new_grid[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int neighbors[8];
            int num_neighbors = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue;
                    int ni = i + x;
                    int nj = j + y;
                    if (ni >= 0 && ni < 5 && nj >= 0 && nj < 5) {
                        neighbors[num_neighbors++] = grid[ni][nj];
                    }
                }
            }
            new_grid[i][j] = update_cell(grid[i][j], neighbors, num_neighbors);
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

void main() {
    int grid[5][5] = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    while (1) {
        simulate(grid);
    }
}