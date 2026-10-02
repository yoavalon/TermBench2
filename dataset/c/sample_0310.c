#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void simulate() {
    int grid[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j] = 0;
        }
    }
    while (1) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                int neighbors = 0;
                if (i > 0) neighbors += grid[i - 1][j];
                if (i < 9) neighbors += grid[i + 1][j];
                if (j > 0) neighbors += grid[i][j - 1];
                if (j < 9) neighbors += grid[i][j + 1];
                if (neighbors > 4) {
                    grid[i][j] = 1;
                } else {
                    grid[i][j] = rand() % 2;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    simulate();
    return 0;
}