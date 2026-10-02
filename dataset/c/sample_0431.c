#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void update_grid(int grid[SIZE][SIZE]) {
    int new_grid[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int alive_neighbors = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < SIZE && nj >= 0 && nj < SIZE && !(di == 0 && dj == 0)) {
                        alive_neighbors += grid[ni][nj];
                    }
                }
            }
            if (grid[i][j] == 1 && (alive_neighbors < 2 || alive_neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (grid[i][j] == 0 && alive_neighbors == 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

void simulate() {
    int grid[SIZE][SIZE];
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    while (1) {
        update_grid(grid);
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    simulate();
    return 0;
}