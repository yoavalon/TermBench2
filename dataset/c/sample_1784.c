#include <stdio.h>

#define SIZE 50
#define STEPS 1000

typedef struct {
    int grid[SIZE][SIZE];
    int size;
} Automaton;

void Automaton_init(Automaton *self, int size) {
    self->size = size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            self->grid[i][j] = 0;
        }
    }
}

void Automaton_update(Automaton *self) {
    int new_grid[SIZE][SIZE];
    for (int i = 0; i < self->size; i++) {
        for (int j = 0; j < self->size; j++) {
            int neighbors = Automaton_count_neighbors(self, i, j);
            if (self->grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (self->grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = self->grid[i][j];
            }
        }
    }
    for (int i = 0; i < self->size; i++) {
        for (int j = 0; j < self->size; j++) {
            self->grid[i][j] = new_grid[i][j];
        }
    }
}

int Automaton_count_neighbors(Automaton *self, int x, int y) {
    int count = 0;
    for (int i = (x > 0 ? x - 1 : 0); i < (x < self->size - 1 ? x + 2 : self->size); i++) {
        for (int j = (y > 0 ? y - 1 : 0); j < (y < self->size - 1 ? y + 2 : self->size); j++) {
            if ((i != x || j != y) && self->grid[i][j] == 1) {
                count += 1;
            }
        }
    }
    return count;
}

int** run_simulation(int size, int steps) {
    static Automaton automaton;
    Automaton_init(&automaton, size);
    for (int _ = 0; _ < steps; _++) {
        Automaton_update(&automaton);
    }
    return automaton.grid;
}

void main() {
    int size = 50;
    int steps = 1000;
    int **result = run_simulation(size, steps);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c", result[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}