#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int size;
    int **state;
} Automaton;

Automaton* Automaton_init(int size, int **initial_state) {
    Automaton *automaton = (Automaton *)malloc(sizeof(Automaton));
    automaton->size = size;
    automaton->state = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        automaton->state[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            automaton->state[i][j] = initial_state[i][j];
        }
    }
    return automaton;
}

void Automaton_update(Automaton *automaton) {
    int **new_state = (int **)malloc(automaton->size * sizeof(int *));
    for (int i = 0; i < automaton->size; i++) {
        new_state[i] = (int *)malloc(automaton->size * sizeof(int));
        for (int j = 0; j < automaton->size; j++) {
            new_state[i][j] = 0;
        }
    }
    for (int i = 0; i < automaton->size; i++) {
        for (int j = 0; j < automaton->size; j++) {
            int neighbors = Automaton_count_neighbors(automaton, i, j);
            if (automaton->state[i][j] == 1) {
                new_state[i][j] = (2 <= neighbors && neighbors <= 3) ? 1 : 0;
            } else {
                new_state[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
    }
    for (int i = 0; i < automaton->size; i++) {
        free(automaton->state[i]);
        automaton->state[i] = new_state[i];
    }
    free(new_state);
}

int Automaton_count_neighbors(Automaton *automaton, int x, int y) {
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if ((0 <= i && i < automaton->size && 0 <= j && j < automaton->size) && !(i == x && j == y)) {
                count += automaton->state[i][j];
            }
        }
    }
    return count;
}

int **generate_initial_state(int size) {
    int **state = (int **)malloc(size * sizeof(int *));
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        state[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            state[i][j] = rand() % 2;
        }
    }
    return state;
}

void main() {
    int size = 10;
    int **initial_state = generate_initial_state(size);
    Automaton *automaton = Automaton_init(size, initial_state);
    while (1) {
        Automaton_update(automaton);
    }
}