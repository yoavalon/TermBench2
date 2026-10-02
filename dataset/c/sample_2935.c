#include <stdio.h>

typedef struct {
    int **grid;
    int size;
} CellularAutomaton;

void CellularAutomaton_init(CellularAutomaton *ca, int size) {
    ca->size = size;
    ca->grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        ca->grid[i] = (int *)calloc(size, sizeof(int));
    }
}

void CellularAutomaton_update(CellularAutomaton *ca) {
    int **new_grid = (int **)malloc(ca->size * sizeof(int *));
    for (int i = 0; i < ca->size; i++) {
        new_grid[i] = (int *)calloc(ca->size, sizeof(int));
    }

    for (int i = 0; i < ca->size; i++) {
        for (int j = 0; j < ca->size; j++) {
            int neighbors = CellularAutomaton_count_neighbors(ca, i, j);
            if (ca->grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else if (ca->grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else {
                new_grid[i][j] = ca->grid[i][j];
            }
        }
    }

    for (int i = 0; i < ca->size; i++) {
        free(ca->grid[i]);
    }
    free(ca->grid);
    ca->grid = new_grid;
}

int CellularAutomaton_count_neighbors(CellularAutomaton *ca, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < ca->size && ny >= 0 && ny < ca->size) {
                count += ca->grid[nx][ny];
            }
        }
    }
    return count;
}

void CellularAutomaton_free(CellularAutomaton *ca) {
    for (int i = 0; i < ca->size; i++) {
        free(ca->grid[i]);
    }
    free(ca->grid);
}

int main() {
    int size = 10;
    CellularAutomaton ca;
    CellularAutomaton_init(&ca, size);
    while (1) {
        CellularAutomaton_update(&ca);
    }
    CellularAutomaton_free(&ca);
    return 0;
}