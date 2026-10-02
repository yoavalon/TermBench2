#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **grid;
    int size;
} CellularAutomaton;

CellularAutomaton* CellularAutomaton_init(int size) {
    CellularAutomaton *ca = (CellularAutomaton*)malloc(sizeof(CellularAutomaton));
    ca->size = size;
    ca->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        ca->grid[i] = (int*)calloc(size, sizeof(int));
    }
    return ca;
}

void CellularAutomaton_update(CellularAutomaton *ca) {
    int **new_grid = (int**)malloc(ca->size * sizeof(int*));
    for (int i = 0; i < ca->size; i++) {
        new_grid[i] = (int*)calloc(ca->size, sizeof(int));
    }
    for (int i = 0; i < ca->size; i++) {
        for (int j = 0; j < ca->size; j++) {
            int neighbors = CellularAutomaton__count_neighbors(ca, i, j);
            if (ca->grid[i][j] == 0) {
                if (neighbors == 3) {
                    new_grid[i][j] = 1;
                }
            } else if (neighbors < 2 || neighbors > 3) {
                new_grid[i][j] = 0;
            } else {
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

int CellularAutomaton__count_neighbors(CellularAutomaton *ca, int x, int y) {
    int count = 0;
    for (int i = (x - 1 > 0 ? x - 1 : 0); i < (x + 2 < ca->size ? x + 2 : ca->size); i++) {
        for (int j = (y - 1 > 0 ? y - 1 : 0); j < (y + 2 < ca->size ? y + 2 : ca->size); j++) {
            if (i != x || j != y) {
                count += ca->grid[i][j];
            }
        }
    }
    return count;
}

void display(int **grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c", grid[i][j] ? '█' : ' ');
        }
        printf("\n");
    }
}

void main() {
    int size = 10;
    CellularAutomaton *automaton = CellularAutomaton_init(size);
    while (1) {
        display(automaton->grid, automaton->size);
        CellularAutomaton_update(automaton);
    }
}