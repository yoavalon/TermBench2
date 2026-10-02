#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **grid;
    int size;
} Automaton;

void Automaton_init(Automaton *self, int size) {
    self->size = size;
    self->grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        self->grid[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            self->grid[i][j] = 0;
        }
    }
}

void Automaton_update(Automaton *self) {
    int **new_grid = (int **)malloc(self->size * sizeof(int *));
    for (int i = 0; i < self->size; i++) {
        new_grid[i] = (int *)malloc(self->size * sizeof(int));
        for (int j = 0; j < self->size; j++) {
            new_grid[i][j] = 0;
        }
    }

    for (int i = 0; i < self->size; i++) {
        for (int j = 0; j < self->size; j++) {
            int neighbors = Automaton_count_neighbors(self, i, j);
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

int Automaton_count_neighbors(Automaton *self, int x, int y) {
    int count = 0;
    for (int i = (x > 0 ? x - 1 : 0); i < (x < self->size - 1 ? x + 2 : self->size); i++) {
        for (int j = (y > 0 ? y - 1 : 0); j < (y < self->size - 1 ? y + 2 : self->size); j++) {
            if ((i != x || j != y) && self->grid[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

typedef struct {
    Automaton *automaton;
} Simulator;

void Simulator_init(Simulator *self, Automaton *automaton) {
    self->automaton = automaton;
}

void Simulator_run(Simulator *self) {
    while (1) {
        Automaton_update(self->automaton);
    }
}

void main() {
    int size = 10;
    Automaton automaton;
    Automaton_init(&automaton, size);
    Simulator simulator;
    Simulator_init(&simulator, &automaton);
    Simulator_run(&simulator);
}