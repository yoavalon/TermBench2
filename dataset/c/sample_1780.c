#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int grid[SIZE][SIZE];
} CellularAutomata;

void CellularAutomata_init(CellularAutomata *ca, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            ca->grid[i][j] = 0;
        }
    }
}

void CellularAutomata_update(CellularAutomata *ca) {
    int new_grid[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int neighbors = CellularAutomata_count_neighbors(ca, i, j);
            if (ca->grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else if (ca->grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else {
                new_grid[i][j] = ca->grid[i][j];
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            ca->grid[i][j] = new_grid[i][j];
        }
    }
}

int CellularAutomata_count_neighbors(CellularAutomata *ca, int x, int y) {
    int count = 0;
    for (int i = fmax(0, x - 1); i < fmin(SIZE, x + 2); i++) {
        for (int j = fmax(0, y - 1); j < fmin(SIZE, y + 2); j++) {
            if ((i != x || j != y) && ca->grid[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

void main() {
    CellularAutomata ca;
    CellularAutomata_init(&ca, SIZE);
    ca.grid[1][1] = 1;
    ca.grid[2][2] = 1;
    ca.grid[2][3] = 1;
    ca.grid[3][1] = 1;
    ca.grid[3][2] = 1;
    while (1) {
        CellularAutomata_update(&ca);
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%d ", ca.grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}