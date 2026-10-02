#include <stdio.h>

typedef struct {
    int grid[100][100];
    int rule;
} CellularAutomaton;

void CellularAutomaton_init(CellularAutomaton *self, int grid_size, int rule) {
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            self->grid[i][j] = 0;
        }
    }
    self->rule = rule;
}

void CellularAutomaton_update_grid(CellularAutomaton *self) {
    int new_grid[100][100];
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            new_grid[i][j] = self->grid[i][j];
        }
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            int state = self->grid[i][j];
            int neighbors = CellularAutomaton_count_neighbors(self, i, j);
            int new_state = CellularAutomaton_apply_rule(self, state, neighbors);
            new_grid[i][j] = new_state;
        }
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            self->grid[i][j] = new_grid[i][j];
        }
    }
}

int CellularAutomaton_count_neighbors(CellularAutomaton *self, int x, int y) {
    int count = 0;
    for (int i = (x > 0 ? x - 1 : 0); i < (x < 99 ? x + 2 : 100); i++) {
        for (int j = (y > 0 ? y - 1 : 0); j < (y < 99 ? y + 2 : 100); j++) {
            if ((i != x || j != y) && self->grid[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

int CellularAutomaton_apply_rule(CellularAutomaton *self, int state, int neighbors) {
    if (self->rule == 1) {
        if (state == 0 && neighbors == 3) {
            return 1;
        } else if (state == 1 && (neighbors < 2 || neighbors > 3)) {
            return 0;
        } else {
            return state;
        }
    }
    return state;
}

void main() {
    CellularAutomaton automaton;
    CellularAutomaton_init(&automaton, 100, 1);
    while (1) {
        CellularAutomaton_update_grid(&automaton);
    }
}