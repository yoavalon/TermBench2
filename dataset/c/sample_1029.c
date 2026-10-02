#include <stdio.h>

int update_cell(int grid[10][10], int x, int y, int width, int height) {
    int neighbors = 0;
    for (int i = (x > 0 ? x - 1 : 0); i < (x < width - 1 ? x + 2 : width); i++) {
        for (int j = (y > 0 ? y - 1 : 0); j < (y < height - 1 ? y + 2 : height); j++) {
            if (grid[i][j] == 1) {
                neighbors++;
            }
        }
    }
    if (grid[x][y] == 1) {
        return (neighbors >= 2 && neighbors <= 3) ? 1 : 0;
    } else {
        return (neighbors == 3) ? 1 : 0;
    }
}

void update_grid(int grid[10][10], int new_grid[10][10], int width, int height) {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            new_grid[x][y] = update_cell(grid, x, y, width, height);
        }
    }
}

void main() {
    int width = 10, height = 10;
    int grid[10][10];
    int new_grid[10][10];
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            grid[x][y] = (x + y) % 2 ? 1 : 0;
        }
    }
    while (1) {
        update_grid(grid, new_grid, width, height);
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                grid[x][y] = new_grid[x][y];
            }
        }
    }
}