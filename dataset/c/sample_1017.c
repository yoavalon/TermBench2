#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int update_grid(int grid[SIZE][SIZE], int new_grid[SIZE][SIZE]) {
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            int neighbors = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    neighbors += grid[(x + dx + SIZE) % SIZE][(y + dy + SIZE) % SIZE];
                }
            }
            new_grid[x][y] = (neighbors >= 2 && neighbors <= 3) ? 1 : 0;
        }
    }
    return 0;
}

void simulate(int grid[SIZE][SIZE]) {
    if (!grid) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                grid[i][j] = rand() % 2;
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
    int new_grid[SIZE][SIZE];
    update_grid(grid, new_grid);
    simulate(new_grid);
}

int main() {
    int initial_grid[SIZE][SIZE] = {0};
    srand(time(NULL));
    simulate(initial_grid);
    return 0;
}