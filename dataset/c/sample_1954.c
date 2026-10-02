#include <stdio.h>

#define WIDTH 10
#define HEIGHT 10

double update_grid(double grid[HEIGHT][WIDTH], int width, int height) {
    double new_grid[HEIGHT][WIDTH];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double neighbors = 0.0;
            for (int dy = -1; dy < 2; dy++) {
                for (int dx = -1; dx < 2; dx++) {
                    if (dx == 0 && dy == 0) continue;
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                        neighbors += grid[ny][nx];
                    }
                }
            }
            new_grid[y][x] = grid[y][x] + 0.1 * (neighbors - 2.0 * grid[y][x]);
        }
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x] = new_grid[y][x];
        }
    }
    return grid;
}

int main() {
    double grid[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = (x == y) ? 0.0 : 1.0;
        }
    }
    for (int i = 0; i < 100; i++) {
        update_grid(grid, WIDTH, HEIGHT);
    }
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%f ", grid[y][x]);
        }
        printf("\n");
    }
    return 0;
}