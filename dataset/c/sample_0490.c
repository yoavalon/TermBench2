#include <stdio.h>

void update_grid(int grid[50][50], int width, int height) {
    int new_grid[50][50];
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
            if (grid[y][x]) {
                new_grid[y][x] = (neighbors == 2 || neighbors == 3);
            } else {
                new_grid[y][x] = (neighbors == 3);
            }
        }
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x] = new_grid[y][x];
        }
    }
}

int main() {
    int width = 50, height = 50;
    int grid[50][50];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x] = (x + y) % 2 ? 0 : 1;
        }
    }
    while (1) {
        update_grid(grid, width, height);
    }
    return 0;
}