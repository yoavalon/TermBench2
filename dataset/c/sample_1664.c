#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int** init_grid(int size) {
    int** grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    return grid;
}

int** update_grid(int** grid, int size) {
    int** new_grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        new_grid[i] = (int*)malloc(size * sizeof(int));
    }

    for (int i = 1; i < size - 1; i++) {
        for (int j = 1; j < size - 1; j++) {
            int neighbors = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    neighbors += grid[i + x][j + y];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (!grid[i][j] && neighbors == 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }

    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);

    return new_grid;
}

void print_grid(int** grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------\n");
}

int main() {
    srand(time(0));
    int** grid = init_grid(SIZE);
    while (1) {
        grid = update_grid(grid, SIZE);
        print_grid(grid, SIZE);
    }
    return 0;
}