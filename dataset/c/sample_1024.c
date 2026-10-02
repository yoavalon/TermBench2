#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int update_grid(int grid[][20], int rules[], int width, int height) {
    int new_grid[20][20];
    memcpy(new_grid, grid, sizeof(new_grid));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int neighbors = 0;
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < height && y >= 0 && y < width) {
                        neighbors += grid[x][y];
                    }
                }
            }
            neighbors -= grid[i][j];
            new_grid[i][j] = rules[neighbors];
        }
    }
    memcpy(grid, new_grid, sizeof(new_grid));
    return 0;
}

void simulate(int grid[][20], int rules[], int width, int height) {
    system("clear");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", grid[i][j] ? '#' : '.');
        }
        printf("\n");
    }
    update_grid(grid, rules, width, height);
    simulate(grid, rules, width, height);
}

void main() {
    int width = 20, height = 20;
    int initial_grid[20][20];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            initial_grid[i][j] = (i + j) % 2 == 0;
        }
    }
    int rules[] = {0, 0, 1, 1, 0, 0, 0, 0, 0};
    simulate(initial_grid, rules, width, height);
}