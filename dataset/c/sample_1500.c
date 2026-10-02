#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int **grid;
    int **rule;
} AutomataSimulator;

AutomataSimulator* AutomataSimulator_init(int size, int **rule) {
    AutomataSimulator *simulator = (AutomataSimulator*)malloc(sizeof(AutomataSimulator));
    simulator->size = size;
    simulator->rule = rule;

    simulator->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        simulator->grid[i] = (int*)calloc(size, sizeof(int));
    }
    return simulator;
}

void AutomataSimulator_update(AutomataSimulator *simulator) {
    int **new_grid = (int**)malloc(simulator->size * sizeof(int*));
    for (int i = 0; i < simulator->size; i++) {
        new_grid[i] = (int*)calloc(simulator->size, sizeof(int));
    }

    for (int i = 0; i < simulator->size; i++) {
        for (int j = 0; j < simulator->size; j++) {
            int state = simulator->grid[i][j];
            int neighbors = AutomataSimulator_count_neighbors(simulator, i, j);
            int new_state = simulator->rule[state][neighbors];
            new_grid[i][j] = new_state;
        }
    }

    for (int i = 0; i < simulator->size; i++) {
        free(simulator->grid[i]);
    }
    free(simulator->grid);
    simulator->grid = new_grid;
}

int AutomataSimulator_count_neighbors(AutomataSimulator *simulator, int x, int y) {
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i >= 0 && i < simulator->size && j >= 0 && j < simulator->size && !(i == x && j == y)) {
                count += simulator->grid[i][j];
            }
        }
    }
    return count;
}

int AutomataSimulator_apply_rule(AutomataSimulator *simulator, int state, int neighbors) {
    return simulator->rule[state][neighbors];
}

void main() {
    int size = 10;
    int rule[2][9] = {
        {0, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0}
    };

    AutomataSimulator *automata = AutomataSimulator_init(size, rule);
    for (int _ = 0; _ < 100; _++) {
        AutomataSimulator_update(automata);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", automata->grid[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size; i++) {
        free(automata->grid[i]);
    }
    free(automata->grid);
    free(automata);
}