#include <stdio.h>

void simulate_flow(int width, int height) {
    int grid[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = 0;
        }
    }
    while (1) {
        int new_grid[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int neighbors = 0;
                for (int dy = -1; dy <= 1; dy += 2) {
                    neighbors += grid[(y + dy + height) % height][(x + 0) % width];
                }
                for (int dx = -1; dx <= 1; dx += 2) {
                    neighbors += grid[(y + 0) % height][(x + dx + width) % width];
                }
                new_grid[y][x] = neighbors / 4;
            }
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
}

int main() {
    simulate_flow(10, 10);
    return 0;
}