#include <stdio.h>

typedef struct {
    int **grid;
    int size;
} Automaton;

Automaton* Automaton_init(int size) {
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

void Automaton_update(Automaton* automaton) {
    int** new_grid = (int**)malloc(automaton->size * sizeof(int*));
    for (int i = 0; i < automaton->size; i++) {
        new_grid[i] = (int*)malloc(automaton->size * sizeof(int));
        for (int j = 0; j < automaton->size; j++) {
            new_grid[i][j] = 0;
        }
    }
    for (int i = 0; i < automaton->size; i++) {
        for (int j = 0; j < automaton->size; j++) {
            int neighbors = Automaton_count_neighbors(automaton, i, j);
            if (automaton->grid[i][j] == 0) {
                if (neighbors == 3) {
                    new_grid[i][j] = 1;
                }
            } else if (neighbors < 2 || neighbors > 3) {
                new_grid[i][j] = 0;
            } else {
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

int Automaton_count_neighbors(Automaton* automaton, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int ni = x + i;
            int nj = y + j;
            if (0 <= ni && ni < automaton->size && 0 <= nj && nj < automaton->size) {
                count += automaton->grid[ni][nj];
            }
        }
    }
    return count;
}

void display(int** grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c", grid[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
}

void main() {
    int size = 10;
    Automaton* automaton = Automaton_init(size);
    automaton->grid[5][5] = 1;
    automaton->grid[5][6] = 1;
    automaton->grid[6][5] = 1;
    automaton->grid[6][6] = 1;
    while (1) {
        display(automaton->grid, automaton->size);
        Automaton_update(automaton);
    }
}