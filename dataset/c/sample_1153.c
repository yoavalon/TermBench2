#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int grid_size;
    int** grid;
} CellAutomata;

CellAutomata* CellAutomata_init(int grid_size) {
    CellAutomata* automata = (CellAutomata*)malloc(sizeof(CellAutomata));
    automata->grid_size = grid_size;
    automata->grid = (int**)malloc(grid_size * sizeof(int*));
    for (int i = 0; i < grid_size; i++) {
        automata->grid[i] = (int*)malloc(grid_size * sizeof(int));
    }
    return automata;
}

void initialize_grid(CellAutomata* automata) {
    srand(time(NULL));
    for (int i = 0; i < automata->grid_size; i++) {
        for (int j = 0; j < automata->grid_size; j++) {
            automata->grid[i][j] = rand() % 2;
        }
    }
}

void update_grid(CellAutomata* automata) {
    int** new_grid = (int**)malloc(automata->grid_size * sizeof(int*));
    for (int i = 0; i < automata->grid_size; i++) {
        new_grid[i] = (int*)malloc(automata->grid_size * sizeof(int));
        for (int j = 0; j < automata->grid_size; j++) {
            new_grid[i][j] = 0;
        }
    }
    for (int i = 0; i < automata->grid_size; i++) {
        for (int j = 0; j < automata->grid_size; j++) {
            int neighbors = count_neighbors(automata, i, j);
            if (automata->grid[i][j] == 1) {
                if (neighbors == 2 || neighbors == 3) {
                    new_grid[i][j] = 1;
                }
            } else if (neighbors == 3) {
                new_grid[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < automata->grid_size; i++) {
        free(automata->grid[i]);
    }
    free(automata->grid);
    automata->grid = new_grid;
}

int count_neighbors(CellAutomata* automata, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int ni = (x + i + automata->grid_size) % automata->grid_size;
            int nj = (y + j + automata->grid_size) % automata->grid_size;
            count += automata->grid[ni][nj];
        }
    }
    return count;
}

void main() {
    int size = 50;
    CellAutomata* automata = CellAutomata_init(size);
    initialize_grid(automata);
    while (1) {
        update_grid(automata);
    }
}