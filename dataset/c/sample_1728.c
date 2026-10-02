#include <stdio.h>

typedef struct {
    int **grid;
    int size;
} Automaton;

Automaton* create_automaton(int size) {
    Automaton *automaton = (Automaton *)malloc(sizeof(Automaton));
    automaton->size = size;
    automaton->grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        automaton->grid[i] = (int *)calloc(size, sizeof(int));
    }
    return automaton;
}

void free_automaton(Automaton *automaton) {
    for (int i = 0; i < automaton->size; i++) {
        free(automaton->grid[i]);
    }
    free(automaton->grid);
    free(automaton);
}

void update(Automaton *automaton) {
    int **new_grid = (int **)malloc(automaton->size * sizeof(int *));
    for (int i = 0; i < automaton->size; i++) {
        new_grid[i] = (int *)calloc(automaton->size, sizeof(int));
    }
    for (int i = 0; i < automaton->size; i++) {
        for (int j = 0; j < automaton->size; j++) {
            int neighbors = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue;
                    int ni = i + x, nj = j + y;
                    if (ni >= 0 && ni < automaton->size && nj >= 0 && nj < automaton->size) {
                        neighbors += automaton->grid[ni][nj];
                    }
                }
            }
            if (automaton->grid[i][j] == 1) {
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
    for (int i = 0; i < automaton->size; i++) {
        free(automaton->grid[i]);
    }
    free(automaton->grid);
    automaton->grid = new_grid;
}

void main() {
    int size = 10;
    Automaton *automaton = create_automaton(size);
    while (1) {
        update(automaton);
    }
    free_automaton(automaton);
}