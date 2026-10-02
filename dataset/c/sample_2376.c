#include <stdio.h>
#include <stdlib.h>

#define SIZE 50
#define RULE 30

typedef struct {
    float grid[SIZE][SIZE];
    int rule;
} CellularAutomata;

typedef struct {
    CellularAutomata ca;
} FluidSimulation;

void CellularAutomata_init(CellularAutomata *ca, int size, int rule) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            ca->grid[i][j] = 0.0f;
        }
    }
    ca->grid[size / 2][size / 2] = 1.0f;
    ca->rule = rule;
}

float CellularAutomata_apply_rule(CellularAutomata *ca, float neighborhood[3][3]) {
    float s = 0.0f;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            s += neighborhood[i][j];
        }
    }
    if (s == 3) {
        return 1.0f;
    } else if (s == 2) {
        return ca->grid[1][1];
    } else {
        return 0.0f;
    }
}

void CellularAutomata_update_grid(CellularAutomata *ca) {
    float new_grid[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            new_grid[i][j] = 0.0f;
        }
    }
    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            float neighborhood[3][3];
            for (int ni = 0; ni < 3; ni++) {
                for (int nj = 0; nj < 3; nj++) {
                    neighborhood[ni][nj] = ca->grid[i - 1 + ni][j - 1 + nj];
                }
            }
            new_grid[i][j] = CellularAutomata_apply_rule(ca, neighborhood);
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            ca->grid[i][j] = new_grid[i][j];
        }
    }
}

void FluidSimulation_init(FluidSimulation *sim, int size, int rule) {
    CellularAutomata_init(&sim->ca, size, rule);
}

void FluidSimulation_simulate(FluidSimulation *sim) {
    while (1) {
        CellularAutomata_update_grid(&sim->ca);
    }
}

int main() {
    FluidSimulation sim;
    FluidSimulation_init(&sim, SIZE, RULE);
    FluidSimulation_simulate(&sim);
    return 0;
}