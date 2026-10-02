#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define DENSITY 0.3
#define STEPS 50

typedef struct {
    int** grid;
    int size;
} AutomataGrid;

void init_grid(AutomataGrid* grid, int size, double density) {
    grid->size = size;
    grid->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        grid->grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            grid->grid[i][j] = (rand() / (double)RAND_MAX) < density ? 1 : 0;
        }
    }
}

void apply_rules(AutomataGrid* grid) {
    int** new_grid = (int**)malloc(grid->size * sizeof(int*));
    for (int i = 0; i < grid->size; i++) {
        new_grid[i] = (int*)malloc(grid->size * sizeof(int));
        for (int j = 0; j < grid->size; j++) {
            new_grid[i][j] = grid->grid[i][j];
        }
    }

    for (int i = 1; i < grid->size - 1; i++) {
        for (int j = 1; j < grid->size - 1; j++) {
            int neighbors = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    neighbors += grid->grid[i + di][j + dj];
                }
            }
            neighbors -= grid->grid[i][j];

            if (grid->grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (grid->grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < grid->size; i++) {
        free(grid->grid[i]);
    }
    free(grid->grid);
    grid->grid = new_grid;
}

void set_boundary_conditions(AutomataGrid* grid) {
    for (int i = 0; i < grid->size; i++) {
        grid->grid[i][0] = grid->grid[i][grid->size - 2];
        grid->grid[i][grid->size - 1] = grid->grid[i][1];
        grid->grid[0][i] = grid->grid[grid->size - 2][i];
        grid->grid[grid->size - 1][i] = grid->grid[1][i];
    }
}

typedef struct {
    AutomataGrid* grid;
    int steps;
} Simulation;

void run(Simulation* sim) {
    for (int step = 0; step < sim->steps; step++) {
        apply_rules(sim->grid);
        set_boundary_conditions(sim->grid);
    }
}

void free_grid(AutomataGrid* grid) {
    for (int i = 0; i < grid->size; i++) {
        free(grid->grid[i]);
    }
    free(grid->grid);
}

int main() {
    srand(time(NULL));
    AutomataGrid grid;
    init_grid(&grid, SIZE, DENSITY);
    Simulation simulation = {&grid, STEPS};
    run(&simulation);
    free_grid(&grid);
    return 0;
}