#include <stdio.h>
#include <stdlib.h>

int** update_grid(int** grid, int width, int height) {
    int** new_grid = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        new_grid[i] = (int*)malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            int neighbors = 0;
            for (int ny = -1; ny <= 1; ny++) {
                for (int nx = -1; nx <= 1; nx++) {
                    if (ny == 0 && nx == 0) continue;
                    int ty = i + ny;
                    int tx = j + nx;
                    if (ty >= 0 && ty < height && tx >= 0 && tx < width) {
                        neighbors += grid[ty][tx];
                    }
                }
            }
            new_grid[i][j] = (neighbors == 3) || (neighbors == 2 && grid[i][j] == 1) ? 1 : 0;
        }
    }
    return new_grid;
}

int** simulate(int** grid, int width, int height, int steps) {
    for (int i = 0; i < steps; i++) {
        grid = update_grid(grid, width, height);
    }
    return grid;
}

void main() {
    int width = 10, height = 10, steps = 5;
    int** initial_grid = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        initial_grid[i] = (int*)calloc(width, sizeof(int));
    }
    initial_grid[5][5] = 1;
    int** result = simulate(initial_grid, width, height, steps);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", result[i][j] ? 'O' : ' ');
        }
        printf("\n");
    }
    for (int i = 0; i < height; i++) {
        free(initial_grid[i]);
        free(result[i]);
    }
    free(initial_grid);
    free(result);
}