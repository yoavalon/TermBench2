#include <stdio.h>

typedef struct {
    int **grid;
    int size;
} CellularAutomata;

void init(CellularAutomata *ca, int size) {
    ca->size = size;
    ca->grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        ca->grid[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            ca->grid[i][j] = 0;
        }
    }
}

void update(CellularAutomata *ca) {
    int **new_grid = (int **)malloc(ca->size * sizeof(int *));
    for (int i = 0; i < ca->size; i++) {
        new_grid[i] = (int *)malloc(ca->size * sizeof(int));
        for (int j = 0; j < ca->size; j++) {
            new_grid[i][j] = 0;
        }
    }
    for (int i = 0; i < ca->size; i++) {
        for (int j = 0; j < ca->size; j++) {
            int neighbors = count_neighbors(ca, i, j);
            if (ca->grid[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = 1;
                }
            } else if (neighbors == 3) {
                new_grid[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < ca->size; i++) {
        free(ca->grid[i]);
    }
    free(ca->grid);
    ca->grid = new_grid;
}

int count_neighbors(CellularAutomata *ca, int x, int y) {
    int count = 0;
    for (int i = (x > 0 ? x - 1 : 0); i <= (x + 1 < ca->size ? x + 1 : ca->size - 1); i++) {
        for (int j = (y > 0 ? y - 1 : 0); j <= (y + 1 < ca->size ? y + 1 : ca->size - 1); j++) {
            if (i != x || j != y) {
                count += ca->grid[i][j];
            }
        }
    }
    return count;
}

void free_grid(CellularAutomata *ca) {
    for (int i = 0; i < ca->size; i++) {
        free(ca->grid[i]);
    }
    free(ca->grid);
}

int main() {
    CellularAutomata ca;
    init(&ca, 10);
    ca.grid[5][5] = 1;
    ca.grid[5][6] = 1;
    ca.grid[6][5] = 1;
    ca.grid[6][6] = 1;
    while (1) {
        update(&ca);
    }
    free_grid(&ca);
    return 0;
}