#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void update_state(int grid[SIZE][SIZE], int new_grid[SIZE][SIZE]) {
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            int neighbors = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (dy == 0 && dx == 0) continue;
                    int ny = y + dy, nx = x + dx;
                    if (ny >= 0 && ny < SIZE && nx >= 0 && nx < SIZE) {
                        neighbors += grid[ny][nx];
                    }
                }
            }
            if (grid[y][x] == 1 && neighbors < 2) {
                new_grid[y][x] = 0;
            } else if (grid[y][x] == 1 && (neighbors == 2 || neighbors == 3)) {
                new_grid[y][x] = 1;
            } else if (grid[y][x] == 1 && neighbors > 3) {
                new_grid[y][x] = 0;
            } else if (grid[y][x] == 0 && neighbors == 3) {
                new_grid[y][x] = 1;
            }
        }
    }
}

void display_grid(int grid[SIZE][SIZE]) {
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            printf("%c", grid[y][x] ? 'O' : ' ');
        }
        printf("\n");
    }
    printf("\n");
}

void simulate(int grid[SIZE][SIZE]) {
    int new_grid[SIZE][SIZE];
    update_state(grid, new_grid);
    display_grid(grid);
    simulate(new_grid);
}

int main() {
    int initial_grid[SIZE][SIZE] = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };
    simulate(initial_grid);
    return 0;
}