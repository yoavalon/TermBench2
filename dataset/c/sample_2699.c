#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **grid;
    int size;
} Automaton;

Automaton* create_automaton(int grid_size) {
    Automaton *automaton = (Automaton*)malloc(sizeof(Automaton));
    automaton->grid = (int**)malloc(grid_size * sizeof(int*));
    for (int i = 0; i < grid_size; i++) {
        automaton->grid[i] = (int*)calloc(grid_size, sizeof(int));
    }
    automaton->size = grid_size;
    return automaton;
}

void update(Automaton *automaton) {
    int **new_grid = (int**)malloc(automaton->size * sizeof(int*));
    for (int i = 0; i < automaton->size; i++) {
        new_grid[i] = (int*)calloc(automaton->size, sizeof(int));
    }

    for (int i = 0; i < automaton->size; i++) {
        for (int j = 0; j < automaton->size; j++) {
            int neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    int ni = i + k;
                    int nj = j + l;
                    if ((k != 0 || l != 0) && ni >= 0 && ni < automaton->size && nj >= 0 && nj < automaton->size) {
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
    }
    free(automaton->grid);
    automaton->grid = new_grid;
}

int count_neighbors(Automaton *automaton, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int ni = x + i;
            int nj = y + j;
            if ((i != 0 || j != 0) && ni >= 0 && ni < automaton->size && nj >= 0 && nj < automaton->size) {
                count += automaton->grid[ni][nj];
            }
        }
    }
    return count;
}

void simulate(Automaton *automaton, int steps) {
    for (int _ = 0; _ < steps; _++) {
        update(automaton);
    }
}

void destroy_automaton(Automaton *automaton) {
    for (int i = 0; i < automaton->size; i++) {
        free(automaton->grid[i]);
    }
    free(automaton->grid);
    free(automaton);
}

int main() {
    int grid_size = 10;
    int steps = 50;
    Automaton *automaton = create_automaton(grid_size);
    simulate(automaton, steps);
    destroy_automaton(automaton);
    return 0;
}