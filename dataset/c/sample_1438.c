#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int grid_size;
    int** grid;
    int* rule_survive;
    int* rule_birth;
    int rule_survive_size;
    int rule_birth_size;
} CellularAutomaton;

CellularAutomaton* CellularAutomaton_init(int grid_size, int* rule_survive, int rule_survive_size, int* rule_birth, int rule_birth_size) {
    CellularAutomaton* ca = (CellularAutomaton*)malloc(sizeof(CellularAutomaton));
    ca->grid_size = grid_size;
    ca->rule_survive = rule_survive;
    ca->rule_birth = rule_birth;
    ca->rule_survive_size = rule_survive_size;
    ca->rule_birth_size = rule_birth_size;

    ca->grid = (int**)malloc(grid_size * sizeof(int*));
    for (int i = 0; i < grid_size; i++) {
        ca->grid[i] = (int*)malloc(grid_size * sizeof(int));
        for (int j = 0; j < grid_size; j++) {
            ca->grid[i][j] = 0;
        }
    }
    ca->grid[grid_size / 2][grid_size / 2] = 1;

    return ca;
}

void CellularAutomaton_update(CellularAutomaton* ca) {
    int** new_grid = (int**)malloc(ca->grid_size * sizeof(int*));
    for (int i = 0; i < ca->grid_size; i++) {
        new_grid[i] = (int*)malloc(ca->grid_size * sizeof(int));
        for (int j = 0; j < ca->grid_size; j++) {
            int neighbors = CellularAutomaton_count_neighbors(ca, i, j);
            new_grid[i][j] = CellularAutomaton_apply_rule(ca, ca->grid[i][j], neighbors);
        }
    }

    for (int i = 0; i < ca->grid_size; i++) {
        free(ca->grid[i]);
    }
    free(ca->grid);
    ca->grid = new_grid;
}

int CellularAutomaton_count_neighbors(CellularAutomaton* ca, int x, int y) {
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i >= 0 && i < ca->grid_size && j >= 0 && j < ca->grid_size && !(i == x && j == y)) {
                count += ca->grid[i][j];
            }
        }
    }
    return count;
}

int CellularAutomaton_apply_rule(CellularAutomaton* ca, int cell, int neighbors) {
    if (cell == 1) {
        for (int i = 0; i < ca->rule_survive_size; i++) {
            if (neighbors == ca->rule_survive[i]) {
                return 1;
            }
        }
    } else if (cell == 0) {
        for (int i = 0; i < ca->rule_birth_size; i++) {
            if (neighbors == ca->rule_birth[i]) {
                return 1;
            }
        }
    }
    return 0;
}

void CellularAutomaton_free(CellularAutomaton* ca) {
    for (int i = 0; i < ca->grid_size; i++) {
        free(ca->grid[i]);
    }
    free(ca->grid);
    free(ca);
}

void main() {
    int size = 50;
    int rule_survive[] = {2, 3};
    int rule_birth[] = {3};
    CellularAutomaton* ca = CellularAutomaton_init(size, rule_survive, 2, rule_birth, 1);

    for (int _ = 0; _ < 100; _++) {
        CellularAutomaton_update(ca);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", ca->grid[i][j]);
        }
        printf("\n");
    }

    CellularAutomaton_free(ca);
}