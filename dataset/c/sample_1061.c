#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 3

void update_grid(int grid[GRID_SIZE][GRID_SIZE]) {
    int new_grid[GRID_SIZE][GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int sum = 0;
            int count = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (i + di >= 0 && i + di < GRID_SIZE && j + dj >= 0 && j + dj < GRID_SIZE) {
                        sum += grid[i + di][j + dj];
                        count++;
                    }
                }
            }
            new_grid[i][j] = sum / count;
        }
    }
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

void display(int grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void simulate(int grid[GRID_SIZE][GRID_SIZE]) {
    display(grid);
    simulate(grid);
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE] = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
    simulate(grid);
    return 0;
}