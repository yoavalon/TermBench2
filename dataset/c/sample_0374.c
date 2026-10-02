#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void simulate() {
    srand(time(NULL));
    int grid[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    while (1) {
        int new_grid[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                int neighbors = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) continue;
                        int ni = i + dx;
                        int nj = j + dy;
                        if (ni >= 0 && ni < 10 && nj >= 0 && nj < 10) {
                            neighbors += grid[ni][nj];
                        }
                    }
                }
                new_grid[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }
}

int main() {
    simulate();
    return 0;
}