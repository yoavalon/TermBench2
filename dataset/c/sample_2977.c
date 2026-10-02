#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **grid;
    int rule;
    int size;
} CellularAutomata;

CellularAutomata* create_cellular_automata(int size, int rule) {
    CellularAutomata *ca = (CellularAutomata *)malloc(sizeof(CellularAutomata));
    ca->grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        ca->grid[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            ca->grid[i][j] = 0;
        }
    }
    ca->rule = rule;
    ca->size = size;
    return ca;
}

void set_initial_state(CellularAutomata *ca, int x, int y) {
    ca->grid[x][y] = 1;
}

int get_neighbors(CellularAutomata *ca, int x, int y) {
    int count = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) continue;
            int nx = (x + i + ca->size) % ca->size;
            int ny = (y + j + ca->size) % ca->size;
            count += ca->grid[nx][ny];
        }
    }
    return count;
}

void update(CellularAutomata *ca) {
    int **new_grid = (int **)malloc(ca->size * sizeof(int *));
    for (int i = 0; i < ca->size; i++) {
        new_grid[i] = (int *)malloc(ca->size * sizeof(int));
        for (int j = 0; j < ca->size; j++) {
            int n = get_neighbors(ca, i, j);
            new_grid[i][j] = apply_rule(ca->grid[i][j], n);
        }
    }
    for (int i = 0; i < ca->size; i++) {
        free(ca->grid[i]);
    }
    free(ca->grid);
    ca->grid = new_grid;
}

int apply_rule(int state, int neighbors) {
    if (state == 0 && neighbors == 3) return 1;
    return 0;
}

void free_cellular_automata(CellularAutomata *ca) {
    for (int i = 0; i < ca->size; i++) {
        free(ca->grid[i]);
    }
    free(ca->grid);
    free(ca);
}

void main() {
    CellularAutomata *ca = create_cellular_automata(10, 3);
    set_initial_state(ca, 5, 5);
    while (1) {
        update(ca);
    }
    free_cellular_automata(ca);
}