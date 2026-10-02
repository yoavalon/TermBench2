#include <stdio.h>

typedef struct {
    int **grid;
    int size;
} CellularAutomata;

typedef struct {
    CellularAutomata automata;
    int size;
} Simulation;

void init_cellular_automata(CellularAutomata *ca, int size) {
    ca->size = size;
    ca->grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        ca->grid[i] = (int *)calloc(size, sizeof(int));
    }
}

void update_cellular_automata(CellularAutomata *ca) {
    int **new_grid = (int **)malloc(ca->size * sizeof(int *));
    for (int i = 0; i < ca->size; i++) {
        new_grid[i] = (int *)calloc(ca->size, sizeof(int));
    }

    for (int i = 0; i < ca->size; i++) {
        for (int j = 0; j < ca->size; j++) {
            int state = ca->grid[i][j];
            int neighbors = 0;

            for (int x = (i > 0 ? i - 1 : 0); x <= (i < ca->size - 1 ? i + 1 : ca->size - 1); x++) {
                for (int y = (j > 0 ? j - 1 : 0); y <= (j < ca->size - 1 ? j + 1 : ca->size - 1); y++) {
                    if ((x != i || y != j) && ca->grid[x][y] == 1) {
                        neighbors++;
                    }
                }
            }

            if (state == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else if (state == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else {
                new_grid[i][j] = state;
            }
        }
    }

    for (int i = 0; i < ca->size; i++) {
        free(ca->grid[i]);
    }
    free(ca->grid);

    ca->grid = new_grid;
}

void init_simulation(Simulation *sim, int size) {
    sim->size = size;
    init_cellular_automata(&sim->automata, size);
}

void run_simulation(Simulation *sim) {
    while (1) {
        update_cellular_automata(&sim->automata);
    }
}

int main() {
    Simulation simulation;
    init_simulation(&simulation, 10);
    run_simulation(&simulation);
    return 0;
}