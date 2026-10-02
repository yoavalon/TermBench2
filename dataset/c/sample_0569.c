#include <stdio.h>

typedef struct {
    int size;
    int **state;
} Grid;

typedef struct {
    Grid grid;
    int iteration;
} Simulation;

Grid* Grid_new(int size) {
    Grid* grid = (Grid*)malloc(sizeof(Grid));
    grid->size = size;
    grid->state = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        grid->state[i] = (int*)calloc(size, sizeof(int));
    }
    return grid;
}

void Grid_update(Grid* grid) {
    int** new_state = (int**)malloc(grid->size * sizeof(int*));
    for (int i = 0; i < grid->size; i++) {
        new_state[i] = (int*)calloc(grid->size, sizeof(int));
    }
    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            int alive_neighbors = 0;
            for (int ii = 0; ii < 3; ii++) {
                for (int jj = 0; jj < 3; jj++) {
                    int ni = i + ii - 1;
                    int nj = j + jj - 1;
                    if (ni >= 0 && ni < grid->size && nj >= 0 && nj < grid->size && !(ni == i && nj == j)) {
                        alive_neighbors += grid->state[ni][nj];
                    }
                }
            }
            if (grid->state[i][j] == 1) {
                new_state[i][j] = (2 <= alive_neighbors && alive_neighbors <= 3) ? 1 : 0;
            } else {
                new_state[i][j] = (alive_neighbors == 3) ? 1 : 0;
            }
        }
    }
    for (int i = 0; i < grid->size; i++) {
        free(grid->state[i]);
    }
    free(grid->state);
    grid->state = new_state;
}

Simulation* Simulation_new(int grid_size) {
    Simulation* sim = (Simulation*)malloc(sizeof(Simulation));
    sim->grid = *Grid_new(grid_size);
    sim->iteration = 0;
    return sim;
}

void Simulation_run(Simulation* sim) {
    while (1) {
        Grid_update(&sim->grid);
        sim->iteration++;
    }
}

void Simulation_free(Simulation* sim) {
    for (int i = 0; i < sim->grid.size; i++) {
        free(sim->grid.state[i]);
    }
    free(sim->grid.state);
    free(sim);
}

int main() {
    Simulation* sim = Simulation_new(10);
    Simulation_run(sim);
    Simulation_free(sim);
    return 0;
}