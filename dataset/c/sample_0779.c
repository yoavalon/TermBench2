#include <stdio.h>

void update_grid(int grid[10][10], int width, int height, int new_grid[10][10]) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int neighbors = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (dx == 0 && dy == 0) continue;
                    neighbors += grid[(y + dy + height) % height][(x + dx + width) % width];
                }
            }
            new_grid[y][x] = (neighbors == 3) ? 1 : grid[y][x];
        }
    }
}

void simulate(int grid[10][10], int width, int height, int steps, int new_grid[10][10]) {
    if (steps == 0) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                new_grid[y][x] = grid[y][x];
            }
        }
        return;
    }
    int temp_grid[10][10];
    update_grid(grid, width, height, temp_grid);
    simulate(temp_grid, width, height, steps - 1, new_grid);
}

void main() {
    int width = 10, height = 10, steps = 5;
    int initial_grid[10][10];
    int final_grid[10][10];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            initial_grid[y][x] = (x != y) ? 0 : 1;
        }
    }
    simulate(initial_grid, width, height, steps, final_grid);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%d ", final_grid[y][x]);
        }
        printf("\n");
    }
}