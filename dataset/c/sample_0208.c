#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int** grid;
    int size;
} AutomataGrid;

AutomataGrid* AutomataGrid_init(int size) {
    AutomataGrid* self = (AutomataGrid*)malloc(sizeof(AutomataGrid));
    self->size = size;
    self->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        self->grid[i] = (int*)calloc(size, sizeof(int));
    }
    return self;
}

void AutomataGrid_update(AutomataGrid* self) {
    int** new_grid = (int**)malloc(self->size * sizeof(int*));
    for (int i = 0; i < self->size; i++) {
        new_grid[i] = (int*)calloc(self->size, sizeof(int));
    }
    for (int i = 0; i < self->size; i++) {
        for (int j = 0; j < self->size; j++) {
            int neighbors = AutomataGrid_count_neighbors(self, i, j);
            if (self->grid[i][j] == 1) {
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
    for (int i = 0; i < self->size; i++) {
        free(self->grid[i]);
    }
    free(self->grid);
    self->grid = new_grid;
}

int AutomataGrid_count_neighbors(AutomataGrid* self, int x, int y) {
    int count = 0;
    for (int i = fmax(0, x - 1); i < fmin(self->size, x + 2); i++) {
        for (int j = fmax(0, y - 1); j < fmin(self->size, y + 2); j++) {
            if (i != x || j != y) {
                count += self->grid[i][j];
            }
        }
    }
    return count;
}

void boundary_conditions(AutomataGrid* grid, int step_limit) {
    int steps = 0;
    while (steps < step_limit) {
        AutomataGrid_update(grid);
        steps++;
    }
}

void main() {
    int size = 10;
    int step_limit = 100;
    AutomataGrid* automata = AutomataGrid_init(size);
    boundary_conditions(automata, step_limit);
    for (int i = 0; i < size; i++) {
        free(automata->grid[i]);
    }
    free(automata->grid);
    free(automata);
}