c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **grid;
    int size;
} Automata;

Automata* Automata_init(int grid_size) {
    Automata *self = (Automata*)malloc(sizeof(Automata));
    self->grid = (int**)malloc(grid_size * sizeof(int*));
    for (int i = 0; i < grid_size; i++) {
        self->grid[i] = (int*)malloc(grid_size * sizeof(int));
        for (int j = 0; j < grid_size; j++) {
            self->grid[i][j] = 0;
        }
    }
    self->size = grid_size;
    return self;
}

void Automata_update(Automata *self) {
    int **new_grid = (int**)malloc(self->size * sizeof(int*));
    for (int i = 0; i < self->size; i++) {
        new_grid[i] = (int*)malloc(self->size * sizeof(int));
        for (int j = 0; j < self->size; j++) {
            int neighbors = 0;
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < self->size && y >= 0 && y < self->size && !(x == i && y == j)) {
                        neighbors += self->grid[x][y];
                    }
                }
            }
            if (self->grid[i][j] == 1) {
                new_grid[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            } else {
                new_grid[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
    }
    for (int i = 0; i < self->size; i++) {
        free(self->grid[i]);
    }
    free(self->grid);
    self->grid = new_grid;
}

void Automata_display(Automata *self) {
    for (int i = 0; i < self->size; i++) {
        for (int j = 0; j < self->size; j++) {
            printf("%c", self->grid[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
    printf("\n");
}

void initialize(Automata *grid) {
    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            if (i == j || i == grid->size - j - 1) {
                grid->grid[i][j] = 1;
            }
        }
    }
}

int main() {
    int size = 10;
    Automata *automata = Automata_init(size);
    initialize(automata);
    while (1) {
        Automata_display(automata);
        Automata_update(automata);
    }
    return 0;
}