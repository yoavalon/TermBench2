c
#include <stdio.h>

void update_grid(int grid[][5], int new_grid[][5], int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int neighbors = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (dx != 0 || dy != 0) {
                        neighbors += grid[(y + dy + height) % height][(x + dx + width) % width];
                    }
                }
            }
            new_grid[y][x] = (neighbors == 3) || (grid[y][x] && neighbors == 2) ? 1 : 0;
        }
    }
}

void simulate(int grid[][5], int new_grid[][5], int width, int height, int steps) {
    if (steps == 0) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                new_grid[y][x] = grid[y][x];
            }
        }
        return;
    }
    update_grid(grid, new_grid, width, height);
    simulate(new_grid, grid, width, height, steps - 1);
}

int main() {
    int width = 5, height = 5, steps = 5;
    int grid[5][5], final_grid[5][5];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x] = (x + y) % 2 ? 1 : 0;
        }
    }
    simulate(grid, final_grid, width, height, steps);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", final_grid[y][x] ? 'O' : ' ');
        }
        printf("\n");
    }
    return 0;
}