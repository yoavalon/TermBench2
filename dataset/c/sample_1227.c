#include <stdio.h>

int** cellular_automata(int size, int steps) {
    int** grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        grid[i] = (int*)calloc(size, sizeof(int));
    }

    for (int step = 0; step < steps; step++) {
        int** new_grid = (int**)malloc(size * sizeof(int*));
        for (int i = 0; i < size; i++) {
            new_grid[i] = (int*)calloc(size, sizeof(int));
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int neighbors = 0;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        neighbors += grid[(i + dx + size) % size][(j + dy + size) % size];
                    }
                }
                neighbors -= grid[i][j];
                new_grid[i][j] = (neighbors == 3) || (grid[i][j] && neighbors == 2);
            }
        }

        for (int i = 0; i < size; i++) {
            free(grid[i]);
        }
        free(grid);
        grid = new_grid;
    }

    return grid;
}

int main() {
    int size = 10;
    int steps = 5;
    int** result = cellular_automata(size, steps);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}