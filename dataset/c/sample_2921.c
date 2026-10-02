#include <stdio.h>

typedef struct {
    int grid[10][10];
    int (*rule)(int);
    int grid_size;
} Automaton;

typedef struct {
    int threshold;
} Rule;

int rule_function(Rule *rule, int count) {
    return count > rule->threshold ? 1 : 0;
}

void automaton_init(Automaton *automaton, int grid_size, Rule *rule) {
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            automaton->grid[i][j] = 0;
        }
    }
    automaton->rule = (int (*)(int))rule_function;
    automaton->grid_size = grid_size;
}

void set_initial_state(Automaton *automaton, int initial_state[10][10]) {
    for (int i = 0; i < automaton->grid_size; i++) {
        for (int j = 0; j < automaton->grid_size; j++) {
            automaton->grid[i][j] = initial_state[i][j];
        }
    }
}

void update(Automaton *automaton) {
    int new_grid[10][10];
    for (int i = 0; i < automaton->grid_size; i++) {
        for (int j = 0; j < automaton->grid_size; j++) {
            int neighbors = (automaton->grid[(i - 1 + 10) % 10][(j - 1 + 10) % 10] + automaton->grid[(i - 1 + 10) % 10][j] + automaton->grid[(i - 1 + 10) % 10][(j + 1) % 10] + automaton->grid[i][(j - 1 + 10) % 10] + automaton->grid[i][(j + 1) % 10] + automaton->grid[(i + 1) % 10][(j - 1 + 10) % 10] + automaton->grid[(i + 1) % 10][j] + automaton->grid[(i + 1) % 10][(j + 1) % 10]);
            new_grid[i][j] = automaton->rule(automaton, neighbors);
        }
    }
    for (int i = 0; i < automaton->grid_size; i++) {
        for (int j = 0; j < automaton->grid_size; j++) {
            automaton->grid[i][j] = new_grid[i][j];
        }
    }
}

void main() {
    int grid_size = 10;
    int initial_state[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    Rule rule;
    rule.threshold = 3;
    Automaton automaton;
    automaton_init(&automaton, grid_size, &rule);
    set_initial_state(&automaton, initial_state);
    while (1) {
        update(&automaton);
    }
}