#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define STEPS 1000

typedef struct {
    int** grid;
    int size;
} CellularAutomaton;

typedef struct {
    CellularAutomaton* ca;
    int steps;
} FluidSimulator;

void cellular_automaton_init(CellularAutomaton* ca, int size) {
    ca->size = size;
    ca->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        ca->grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            ca->grid[i][j] = rand() % 2;
        }
    }
}

void cellular_automaton_update(CellularAutomaton* ca) {
    int** new_grid = (int**)malloc(ca->size * sizeof(int*));
    for (int i = 0; i < ca->size; i++) {
        new_grid[i] = (int*)malloc(ca->size * sizeof(int));
    }
    for (int i = 0; i < ca->size; i++) {
        for (int j = 0; j < ca->size; j++) {
            int sum = 0;
            for (int ni = -1; ni <= 1; ni++) {
                for (int nj = -1; nj <= 1; nj++) {
                    int ii = (i + ni + ca->size) % ca->size;
                    int jj = (j + nj + ca->size) % ca->size;
                    sum += ca->grid[ii][jj];
                }
            }
            new_grid[i][j] = (sum == 3) || (ca->grid[i][j] == 1 && sum == 2);
        }
    }
    for (int i = 0; i < ca->size; i++) {
        free(ca->grid[i]);
    }
    free(ca->grid);
    ca->grid = new_grid;
}

void cellular_automaton_get_state(CellularAutomaton* ca, int** state) {
    for (int i = 0; i < ca->size; i++) {
        for (int j = 0; j < ca->size; j++) {
            state[i][j] = ca->grid[i][j];
        }
    }
}

void fluid_simulator_init(FluidSimulator* fs, int size, int steps) {
    fs->size = size;
    fs->steps = steps;
    fs->ca = (CellularAutomaton*)malloc(sizeof(CellularAutomaton));
    cellular_automaton_init(fs->ca, size);
}

void fluid_simulator_simulate(FluidSimulator* fs) {
    for (int i = 0; i < fs->steps; i++) {
        cellular_automaton_update(fs->ca);
    }
}

void fluid_simulator_get_result(FluidSimulator* fs, int** result) {
    cellular_automaton_get_state(fs->ca, result);
}

void main() {
    srand(time(NULL));
    FluidSimulator simulator;
    fluid_simulator_init(&simulator, SIZE, STEPS);
    fluid_simulator_simulate(&simulator);
    int** result = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; i++) {
        result[i] = (int*)malloc(SIZE * sizeof(int));
    }
    fluid_simulator_get_result(&simulator, result);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < SIZE; i++) {
        free(result[i]);
    }
    free(result);
    free(simulator.ca->grid);
    free(simulator.ca);
    free(simulator.ca);
}