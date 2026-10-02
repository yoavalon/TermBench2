c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int initialize_grid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    return 0;
}

int update_grid(int grid[SIZE][SIZE], int new_grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int neighbors = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    neighbors += grid[(i + dx + SIZE) % SIZE][(j + dy + SIZE) % SIZE];
                }
            }
            new_grid[i][j] = (neighbors == 3) ? 1 : (neighbors == 2) ? grid[i][j] : 0;
        }
    }
    return 0;
}

int main() {
    int grid[SIZE][SIZE], new_grid[SIZE][SIZE];
    srand(time(NULL));
    initialize_grid(grid);
    while (1) {
        update_grid(grid, new_grid);
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%c", (new_grid[i][j] == 1) ? 'O' : ' ');
            }
            printf("\n");
        }
        printf("\n");
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
    return 0;
}