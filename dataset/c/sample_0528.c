#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int** grid;
    int size;
} Automaton;

typedef struct {
    Automaton* automaton;
} BoundaryHandler;

Automaton* create_automaton(int size) {
    Automaton* automaton = (Automaton*)malloc(sizeof(Automaton));
    automaton->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        automaton->grid[i] = (int*)calloc(size, sizeof(int));
    }
    automaton->size = size;
    return automaton;
}

void update(Automaton* automaton) {
    int** new_grid = (int**)malloc(automaton->size * sizeof(int*));
    for (int i = 0; i < automaton->size; i++) {
        new_grid[i] = (int*)calloc(automaton->size, sizeof(int));
    }
    for (int i = 0; i < automaton->size; i++) {
        for (int j = 0; j < automaton->size; j++) {
            int neighbors = automaton->grid[(i - 1 + automaton->size) % automaton->size][(j - 1 + automaton->size) % automaton->size] +
                           automaton->grid[(i - 1 + automaton->size) % automaton->size][j] +
                           automaton->grid[(i - 1 + automaton->size) % automaton->size][(j + 1) % automaton->size] +
                           automaton->grid[i][(j - 1 + automaton->size) % automaton->size] +
                           automaton->grid[i][(j + 1) % automaton->size] +
                           automaton->grid[(i + 1) % automaton->size][(j - 1 + automaton->size) % automaton->size] +
                           automaton->grid[(i + 1) % automaton->size][j] +
                           automaton->grid[(i + 1) % automaton->size][(j + 1) % automaton->size];
            if (automaton->grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (automaton->grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < automaton->size; i++) {
        free(automaton->grid[i]);
    }
    free(automaton->grid);
    automaton->grid = new_grid;
}

BoundaryHandler* create_boundary_handler(Automaton* automaton) {
    BoundaryHandler* handler = (BoundaryHandler*)malloc(sizeof(BoundaryHandler));
    handler->automaton = automaton;
    return handler;
}

void apply_boundary_conditions(BoundaryHandler* handler) {
    for (int i = 0; i < handler->automaton->size; i++) {
        handler->automaton->grid[0][i] = 0;
        handler->automaton->grid[handler->automaton->size - 1][i] = 0;
        handler->automaton->grid[i][0] = 0;
        handler->automaton->grid[i][handler->automaton->size - 1] = 0;
    }
}

void main() {
    int size = 100;
    Automaton* automaton = create_automaton(size);
    BoundaryHandler* boundary_handler = create_boundary_handler(automaton);
    automaton->grid[1][2] = 1;
    automaton->grid[2][3] = 1;
    automaton->grid[3][1] = 1;
    automaton->grid[3][2] = 1;
    automaton->grid[3][3] = 1;
    while (1) {
        apply_boundary_conditions(boundary_handler);
        update(automaton);
    }
}