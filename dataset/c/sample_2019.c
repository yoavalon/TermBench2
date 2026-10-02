#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define STEPS 50

typedef struct {
    int grid[SIZE][SIZE];
    int rules[9]; // Max possible sum of neighbors is 8 (3x3 grid of 1s)
} Automaton;

typedef struct {
    Automaton automaton;
    int steps;
} Simulation;

void init_automaton(Automaton *automaton, int size, int *rules) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            automaton->grid[i][j] = rand() % 2;
        }
    }
    for (int i = 0; i < 9; i++) {
        automaton->rules[i] = 0;
    }
    for (int i = 0; i < 2; i++) {
        automaton->rules[rules[i*2]] = rules[i*2 + 1];
    }
}

void apply_rules(Automaton *automaton) {
    int new_grid[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            new_grid[i][j] = automaton->grid[i][j];
        }
    }
    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            int total = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    total += automaton->grid[i + x][j + y];
                }
            }
            if (total >= 0 && total < 9) {
                new_grid[i][j] = automaton->rules[total];
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            automaton->grid[i][j] = new_grid[i][j];
        }
    }
}

void update(Automaton *automaton) {
    apply_rules(automaton);
}

void init_simulation(Simulation *simulation, int size, int *rules, int steps) {
    init_automaton(&simulation->automaton, size, rules);
    simulation->steps = steps;
}

void run(Simulation *simulation) {
    for (int i = 0; i < simulation->steps; i++) {
        update(&simulation->automaton);
    }
}

int main() {
    srand(time(NULL));
    int size = SIZE;
    int rules[] = {3, 1, 12, 1};
    int steps = STEPS;
    Simulation simulation;
    init_simulation(&simulation, size, rules, steps);
    run(&simulation);
    return 0;
}