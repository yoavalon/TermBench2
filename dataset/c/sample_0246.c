c
#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

int initialize_grid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
        }
    }
    grid[SIZE / 2][SIZE / 2] = 1;
    return 0;
}

void apply_boundary_conditions(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        grid[0][i] = 0;
        grid[SIZE - 1][i] = 0;
        grid[i][0] = 0;
        grid[i][SIZE - 1] = 0;
    }
}

void update_grid(int grid[SIZE][SIZE], int new_grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            new_grid[i][j] = grid[i][j];
        }
    }
    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            int neighbors = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    neighbors += grid[i + di][j + dj];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                }
            } else if (neighbors == 3) {
                new_grid[i][j] = 1;
            }
        }
    }
}

void simulate(int steps) {
    int grid[SIZE][SIZE];
    int new_grid[SIZE][SIZE];
    initialize_grid(grid);
    apply_boundary_conditions(grid);
    for (int step = 0; step < steps; step++) {
        update_grid(grid, new_grid);
        apply_boundary_conditions(new_grid);
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int steps = 100;
    simulate(steps);
    return 0;
}