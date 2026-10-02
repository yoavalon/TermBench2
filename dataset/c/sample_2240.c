#include <stdio.h>

double update_grid(double grid[][100], int width, int height) {
    double new_grid[100][100];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double neighbors = 0.0;
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    int nx = (x + i + width) % width;
                    int ny = (y + j + height) % height;
                    neighbors += grid[ny][nx];
                }
            }
            new_grid[y][x] = neighbors / 9.0;
        }
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x] = new_grid[y][x];
        }
    }
}

void simulate(int width, int height) {
    double grid[100][100];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y][x] = 0.0;
        }
    }
    while (1) {
        update_grid(grid, width, height);
    }
}

int main() {
    simulate(100, 100);
    return 0;
}