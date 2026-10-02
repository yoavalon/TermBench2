#include <stdio.h>

#define SIZE 10

void update(int grid[SIZE][SIZE], int size, int new_grid[SIZE][SIZE]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int neighbors = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    neighbors += grid[(i + dx + size) % size][(j + dy + size) % size];
                }
            }
            new_grid[i][j] = (neighbors == 3) ? 1 : (neighbors == 2) ? grid[i][j] : 0;
        }
    }
}

void simulate(int grid[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c", grid[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
    int new_grid[SIZE][SIZE];
    update(grid, size, new_grid);
    simulate(new_grid, size);
}

int main() {
    int grid[SIZE][SIZE] = {0};
    grid[SIZE / 2][SIZE / 2] = 1;
    simulate(grid, SIZE);
    return 0;
}