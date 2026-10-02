#include <stdio.h>

#define WIDTH 50
#define HEIGHT 50
#define STEPS 100

void update_state(int grid[HEIGHT][WIDTH], int width, int height, int new_grid[HEIGHT][WIDTH]) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int neighbors = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (dy == 0 && dx == 0) continue;
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                        neighbors += grid[ny][nx];
                    }
                }
            }
            if (grid[y][x] == 1) {
                new_grid[y][x] = (neighbors >= 2 && neighbors <= 3) ? 1 : 0;
            } else {
                new_grid[y][x] = (neighbors == 3) ? 1 : 0;
            }
        }
    }
}

void simulate(int grid[HEIGHT][WIDTH], int width, int height, int steps) {
    int new_grid[HEIGHT][WIDTH];
    for (int i = 0; i < steps; i++) {
        update_state(grid, width, height, new_grid);
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                grid[y][x] = new_grid[y][x];
            }
        }
    }
}

int main() {
    int grid[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = (x + y) % 2 ? 1 : 0;
        }
    }
    simulate(grid, WIDTH, HEIGHT, STEPS);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", grid[y][x] ? 'O' : ' ');
        }
        printf("\n");
    }
    return 0;
}