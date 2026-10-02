#include <stdio.h>

#define WIDTH 10
#define HEIGHT 10

int update_grid(int grid[HEIGHT][WIDTH]) {
    int new_grid[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int neighbors = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (dx == 0 && dy == 0) continue;
                    neighbors += grid[(y + dy + HEIGHT) % HEIGHT][(x + dx + WIDTH) % WIDTH];
                }
            }
            if (grid[y][x] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[y][x] = 0;
            } else if (grid[y][x] == 0 && neighbors == 3) {
                new_grid[y][x] = 1;
            } else {
                new_grid[y][x] = grid[y][x];
            }
        }
    }
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = new_grid[y][x];
        }
    }
    return 0;
}

int main() {
    int grid[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = (x + y) % 2;
        }
    }
    while (1) {
        update_grid(grid);
    }
    return 0;
}