#include <stdio.h>

int update_state(int grid[5][5]) {
    int new_grid[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int neighbors = 0;
            if (i > 0) neighbors += grid[i-1][j];
            if (i < 4) neighbors += grid[i+1][j];
            if (j > 0) neighbors += grid[i][j-1];
            if (j < 4) neighbors += grid[i][j+1];
            new_grid[i][j] = (neighbors == 3) || (grid[i][j] && neighbors == 2) ? 1 : 0;
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
    return 0;
}

void simulate(int grid[5][5]) {
    while (1) {
        update_state(grid);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    int initial_grid[5][5] = {{0, 0, 0, 0, 0}, {0, 1, 1, 0, 0}, {0, 1, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    simulate(initial_grid);
    return 0;
}