#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int** grid;
    int size;
} CellularAutomata;

CellularAutomata* CellularAutomata_init(int size) {
    CellularAutomata* ca = (CellularAutomata*)malloc(sizeof(CellularAutomata));
    ca->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        ca->grid[i] = (int*)calloc(size, sizeof(int));
    }
    ca->size = size;
    return ca;
}

void CellularAutomata_update(CellularAutomata* ca) {
    int** new_grid = (int**)malloc(ca->size * sizeof(int*));
    for (int i = 0; i < ca->size; i++) {
        new_grid[i] = (int*)calloc(ca->size, sizeof(int));
    }
    for (int i = 0; i < ca->size; i++) {
        for (int j = 0; j < ca->size; j++) {
            int neighbors = CellularAutomata__count_neighbors(ca, i, j);
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

int CellularAutomata__count_neighbors(CellularAutomata* ca, int x, int y) {
    int count = 0;
    for (int i = (x > 0 ? x - 1 : 0); i < (x + 2 < ca->size ? x + 2 : ca->size); i++) {
        for (int j = (y > 0 ? y - 1 : 0); j < (y + 2 < ca->size ? y + 2 : ca->size); j++) {
            if ((i != x || j != y) && ca->grid[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

void CellularAutomata_free(CellularAutomata* ca) {
    for (int i = 0; i < ca->size; i++) {
        free(ca->grid[i]);
    }
    free(ca->grid);
    free(ca);
}

void main() {
    int size = 10;
    CellularAutomata* ca = CellularAutomata_init(size);
    for (int _ = 0; _ < 100; _++) {
        CellularAutomata_update(ca);
    }
    for (int i = 0; i < ca->size; i++) {
        for (int j = 0; j < ca->size; j++) {
            printf("%c", ca->grid[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
    CellularAutomata_free(ca);
}