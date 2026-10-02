#include <stdio.h>
#include <stdlib.h>

int** update_state(int** grid, int width, int height) {
    int** new_grid = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        new_grid[i] = (int*)calloc(width, sizeof(int));
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int neighbors = 0;
            for (int dy = -1; dy < 2; dy++) {
                for (int dx = -1; dx < 2; dx++) {
                    if (dy == 0 && dx == 0) {
                        continue;
                    }
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                        neighbors += grid[ny][nx];
                    }
                }
            }
            if (grid[y][x] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_grid[y][x] = 0;
                } else {
                    new_grid[y][x] = 1;
                }
            } else if (neighbors == 3) {
                new_grid[y][x] = 1;
            }
        }
    }
    return new_grid;
}

int** run_simulation(int** grid, int width, int height, int steps) {
    if (steps == 0) {
        return grid;
    } else {
        grid = update_state(grid, width, height);
        return run_simulation(grid, width, height, steps - 1);
    }
}

void main() {
    int width = 10;
    int height = 10;
    int initial_grid[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    int steps = 10;
    int** final_grid = run_simulation((int**)initial_grid, width, height, steps);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%d ", final_grid[y][x]);
        }
        printf("\n");
    }
}