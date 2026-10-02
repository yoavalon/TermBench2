#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int** grid;
    int size;
} Automata;

Automata* Automata_new(int size) {
    Automata* self = (Automata*)malloc(sizeof(Automata));
    self->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        self->grid[i] = (int*)calloc(size, sizeof(int));
    }
    self->size = size;
    return self;
}

void Automata_update(Automata* self) {
    int** new_grid = (int**)malloc(self->size * sizeof(int*));
    for (int i = 0; i < self->size; i++) {
        new_grid[i] = (int*)calloc(self->size, sizeof(int));
    }
    for (int i = 0; i < self->size; i++) {
        for (int j = 0; j < self->size; j++) {
            int neighbors = Automata_count_neighbors(self, i, j);
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

int Automata_count_neighbors(Automata* self, int x, int y) {
    int count = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
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

void Automata_free(Automata* self) {
    for (int i = 0; i < self->size; i++) {
        free(self->grid[i]);
    }
    free(self->grid);
    free(self);
}

void main() {
    int size = 50;
    Automata* automata = Automata_new(size);
    automata->grid[25][25] = 1;
    automata->grid[26][25] = 1;
    automata->grid[27][25] = 1;
    while (1) {
        Automata_update(automata);
    }
    Automata_free(automata);
}