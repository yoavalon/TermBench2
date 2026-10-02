#include <stdio.h>

#define SIZE 5

void update_state(double grid[SIZE][SIZE], double new_grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            double neighbors = 0.0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) {
                        continue;
                    }
                    int ni = i + x;
                    int nj = j + y;
                    if (ni >= 0 && ni < SIZE && nj >= 0 && nj < SIZE) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            new_grid[i][j] = neighbors / 9.0;
        }
    }
}

void run_simulation(int steps) {
    double grid[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
    for (int step = 0; step < steps; step++) {
        double new_grid[SIZE][SIZE];
        update_state(grid, new_grid);
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%f ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    run_simulation(10);
    return 0;
}