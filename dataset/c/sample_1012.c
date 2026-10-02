#include <stdio.h>

void update_grid(int grid[5][5], int new_grid[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int live_neighbors = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue;
                    int ni = i + x, nj = j + y;
                    if (ni >= 0 && ni < 5 && nj >= 0 && nj < 5) {
                        live_neighbors += grid[ni][nj];
                    }
                }
            }
            if (grid[i][j] && (live_neighbors == 2 || live_neighbors == 3)) {
                new_grid[i][j] = 1;
            } else if (!grid[i][j] && live_neighbors == 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = 0;
            }
        }
    }
}

void simulate(int grid[5][5]) {
    display(grid);
    int new_grid[5][5];
    update_grid(grid, new_grid);
    simulate(new_grid);
}

void display(int grid[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c", grid[i][j] ? '█' : ' ');
        }
        printf("\n");
    }
}

int main() {
    int initial_grid[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };
    simulate(initial_grid);
    return 0;
}