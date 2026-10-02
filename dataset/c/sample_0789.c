#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10
#define STEPS 5

int** update_grid(int** grid, int width, int height) {
    int** new_grid = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        new_grid[i] = (int*)calloc(width, sizeof(int));
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int neighbors = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (dx == 0 && dy == 0) continue;
                    neighbors += grid[(y + dy + height) % height][(x + dx + width) % width];
                }
            }
            new_grid[y][x] = (neighbors == 3) || (grid[y][x] && neighbors == 2) ? 1 : 0;
        }
    }

    for (int i = 0; i < height; i++) {
        free(grid[i]);
    }
    free(grid);

    return new_grid;
}

int** simulate(int** grid, int width, int height, int steps) {
    if (steps == 0) {
        return grid;
    }
    return simulate(update_grid(grid, width, height), width, height, steps - 1);
}

int main() {
    int** initial_grid = (int**)malloc(HEIGHT * sizeof(int*));
    for (int i = 0; i < HEIGHT; i++) {
        initial_grid[i] = (int*)malloc(WIDTH * sizeof(int));
        for (int j = 0; j < WIDTH; j++) {
            initial_grid[i][j] = (j % 2) ? 0 : 1;
        }
    }

    int** final_grid = simulate(initial_grid, WIDTH, HEIGHT, STEPS);

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", final_grid[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < HEIGHT; i++) {
        free(final_grid[i]);
    }
    free(final_grid);

    return 0;
}