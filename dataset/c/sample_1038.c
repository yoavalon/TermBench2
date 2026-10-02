#include <stdio.h>

void update_grid(int grid[][50], int width, int height, int new_grid[][50]) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int neighbors = 0;
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    int nx = (x + i + width) % width;
                    int ny = (y + j + height) % height;
                    neighbors += grid[ny][nx];
                }
            }
            new_grid[y][x] = (2 < neighbors && neighbors < 4) ? 1 : 0;
        }
    }
}

void simulate(int grid[][50], int width, int height) {
    print_grid(grid, width, height);
    int new_grid[50][50];
    update_grid(grid, width, height, new_grid);
    simulate(new_grid, width, height);
}

void print_grid(int grid[][50], int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", grid[y][x] ? '#' : ' ');
        }
        printf("\n");
    }
}

int main() {
    int width = 50, height = 50;
    int grid[50][50] = {0};
    grid[25][25] = 1;
    simulate(grid, width, height);
    return 0;
}