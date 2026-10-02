#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int** grid;
    char* boundary_type;
    int size;
} Automata;

typedef struct {
    Automata* automata;
    int steps;
} Simulation;

Automata* Automata_init(int size, char* boundary_type) {
    Automata* automata = (Automata*)malloc(sizeof(Automata));
    automata->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        automata->grid[i] = (int*)calloc(size, sizeof(int));
    }
    automata->boundary_type = boundary_type;
    automata->size = size;
    return automata;
}

void Automata_apply_boundary_conditions(Automata* automata) {
    if (strcmp(automata->boundary_type, "fixed") == 0) {
        for (int i = 0; i < automata->size; i++) {
            automata->grid[i][0] = 1;
            automata->grid[i][automata->size - 1] = 1;
            automata->grid[0][i] = 1;
            automata->grid[automata->size - 1][i] = 1;
        }
    } else if (strcmp(automata->boundary_type, "periodic") == 0) {
        for (int i = 0; i < automata->size; i++) {
            automata->grid[i][0] = automata->grid[i][automata->size - 2];
            automata->grid[i][automata->size - 1] = automata->grid[i][1];
            automata->grid[0][i] = automata->grid[automata->size - 2][i];
            automata->grid[automata->size - 1][i] = automata->grid[1][i];
        }
    }
}

void Automata_update_grid(Automata* automata) {
    int** new_grid = (int**)malloc(automata->size * sizeof(int*));
    for (int i = 0; i < automata->size; i++) {
        new_grid[i] = (int*)malloc(automata->size * sizeof(int));
        for (int j = 0; j < automata->size; j++) {
            new_grid[i][j] = automata->grid[i][j];
        }
    }
    for (int i = 1; i < automata->size - 1; i++) {
        for (int j = 1; j < automata->size - 1; j++) {
            int neighbors = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    neighbors += automata->grid[i + di][j + dj];
                }
            }
            neighbors -= automata->grid[i][j];
            if (automata->grid[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                }
            } else if (neighbors == 3) {
                new_grid[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < automata->size; i++) {
        free(automata->grid[i]);
        automata->grid[i] = new_grid[i];
    }
    free(new_grid);
}

Simulation* Simulation_init(Automata* automata, int steps) {
    Simulation* simulation = (Simulation*)malloc(sizeof(Simulation));
    simulation->automata = automata;
    simulation->steps = steps;
    return simulation;
}

void Simulation_run(Simulation* simulation) {
    for (int i = 0; i < simulation->steps; i++) {
        Automata_apply_boundary_conditions(simulation->automata);
        Automata_update_grid(simulation->automata);
    }
}

void Automata_free(Automata* automata) {
    for (int i = 0; i < automata->size; i++) {
        free(automata->grid[i]);
    }
    free(automata->grid);
    free(automata);
}

void Simulation_free(Simulation* simulation) {
    Automata_free(simulation->automata);
    free(simulation);
}

void main() {
    int size = 10;
    char* boundary_type = "fixed";
    int steps = 50;
    Automata* automata = Automata_init(size, boundary_type);
    Simulation* simulation = Simulation_init(automata, steps);
    Simulation_run(simulation);
    Simulation_free(simulation);
}