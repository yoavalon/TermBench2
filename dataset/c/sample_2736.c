#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void update(int grid[SIZE][SIZE]) {
    int new_grid[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int sum = grid[i][j];
            sum += grid[(i + 1) % SIZE][j];
            sum += grid[(i - 1 + SIZE) % SIZE][j];
            sum += grid[i][(j + 1) % SIZE];
            sum += grid[i][(j - 1 + SIZE) % SIZE];
            new_grid[i][j] = sum % 2;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    int grid[SIZE][SIZE] = {0};
    grid[50][50] = 1;
    while (1) {
        update(grid);
    }
    return 0;
}