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

void update(Automaton *automaton) {
    int **new_grid = (int **)malloc(automaton->size * sizeof(int *));
    for (int i = 0; i < automaton->size; i++) {
        new_grid[i] = (int *)calloc(automaton->size, sizeof(int));
    }

    for (int i = 0; i < automaton->size; i++) {
        for (int j = 0; j < automaton->size; j++) {
            int neighbors = 0;
            for (int k = -1; k < 2; k++) {
                for (int l = -1; l < 2; l++) {
                    if (k == 0 && l == 0) continue;
                    int ni = i + k;
                    int nj = j + l;
                    if (ni >= 0 && ni < automaton->size && nj >= 0 && nj < automaton->size) {
                        neighbors += automaton->grid[ni][nj];
                    }
                }
            }
            if (automaton->grid[i][j] == 0) {
                if (neighbors == 3) {
                    new_grid[i][j] = 1;
                }
            } else if (neighbors < 2 || neighbors > 3) {
                new_grid[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < automaton->size; i++) {
        free(automaton->grid[i]);
    }
    free(automaton->grid);
    automaton->grid = new_grid;
}

int all_zeros(Automaton *automaton) {
    for (int i = 0; i < automaton->size; i++) {
        for (int j = 0; j < automaton->size; j++) {
            if (automaton->grid[i][j] != 0) {
                return 0;
            }
        }
    }
    return 1;
}

void destroy_automaton(Automaton *automaton) {
    for (int i = 0; i < automaton->size; i++) {
        free(automaton->grid[i]);
    }
    free(automaton->grid);
    free(automaton);
}

void main() {
    Automaton *automaton = create_automaton(10);
    for (int _ = 0; _ < 50; _++) {
        update(automaton);
        if (all_zeros(automaton)) {
            break;
        }
    }
    destroy_automaton(automaton);
}