#include <stdio.h>

typedef struct {
    int **grid;
    int size;
} Automaton;

Automaton *Automaton_init(int size) {
    Automaton *self = (Automaton *)malloc(sizeof(Automaton));
    self->grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        self->grid[i] = (int *)calloc(size, sizeof(int));
    }
    self->size = size;
    return self;
}

void Automaton_update(Automaton *self) {
    int **new_grid = (int **)malloc(self->size * sizeof(int *));
    for (int i = 0; i < self->size; i++) {
        new_grid[i] = (int *)calloc(self->size, sizeof(int));
    }
    for (int i = 0; i < self->size; i++) {
        for (int j = 0; j < self->size; j++) {
            int neighbors = Automaton_count_neighbors(self, i, j);
            if (self->grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else if (self->grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else {
                new_grid[i][j] = self->grid[i][j];
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
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < self->size && ny >= 0 && ny < self->size) {
                count += self->grid[nx][ny];
            }
        }
    }
    return count;
}

void run_simulation(int size) {
    Automaton *automaton = Automaton_init(size);
    automaton->grid[1][1] = 1;
    automaton->grid[1][2] = 1;
    automaton->grid[2][1] = 1;
    automaton->grid[2][2] = 1;
    while (1) {
        Automaton_update(automaton);
    }
    for (int i = 0; i < size; i++) {
        free(automaton->grid[i]);
    }
    free(automaton->grid);
    free(automaton);
}

int main() {
    run_simulation(5);
    return 0;
}