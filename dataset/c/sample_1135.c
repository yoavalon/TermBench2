#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int** grid;
    int size;
} Automaton;

Automaton* create_automaton(int size) {
    Automaton* automaton = (Automaton*)malloc(sizeof(Automaton));
    automaton->size = size;
    automaton->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        automaton->grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            automaton->grid[i][j] = 0;
        }
    }
    return automaton;
}

void update(Automaton* automaton) {
    int** new_grid = (int**)malloc(automaton->size * sizeof(int*));
    for (int i = 0; i < automaton->size; i++) {
        new_grid[i] = (int*)malloc(automaton->size * sizeof(int));
    }

    for (int i = 0; i < automaton->size; i++) {
        for (int j = 0; j < automaton->size; j++) {
            int neighbors = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < automaton->size && nj >= 0 && nj < automaton->size) {
                        neighbors += automaton->grid[ni][nj];
                    }
                }
            }
            if (automaton->grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else if (automaton->grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else {
                new_grid[i][j] = automaton->grid[i][j];
            }
        }
    }

    for (int i = 0; i < automaton->size; i++) {
        free(automaton->grid[i]);
        automaton->grid[i] = new_grid[i];
    }
    free(new_grid);
}

void main() {
    int size = 50;
    Automaton* automaton = create_automaton(size);
    automaton->grid[size / 2][size / 2] = 1;
    update(automaton);
    while (1) {
        update(automaton);
    }
}