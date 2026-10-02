#include <stdio.h>

typedef struct {
    int **grid;
    int steps;
    int step_count;
} FluidSimulator;

FluidSimulator* FluidSimulator_init(int grid_size, int steps) {
    FluidSimulator *sim = (FluidSimulator *)malloc(sizeof(FluidSimulator));
    sim->grid = (int **)malloc(grid_size * sizeof(int *));
    for (int i = 0; i < grid_size; i++) {
        sim->grid[i] = (int *)calloc(grid_size, sizeof(int));
    }
    sim->steps = steps;
    sim->step_count = 0;
    return sim;
}

void FluidSimulator_update(FluidSimulator *sim) {
    int grid_size = sizeof(sim->grid) / sizeof(sim->grid[0]);
    int **new_grid = (int **)malloc(grid_size * sizeof(int *));
    for (int i = 0; i < grid_size; i++) {
        new_grid[i] = (int *)calloc(grid_size, sizeof(int));
    }

    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            int neighbors = FluidSimulator_count_neighbors(sim, i, j);
            if (sim->grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (sim->grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = sim->grid[i][j];
            }
        }
    }

    for (int i = 0; i < grid_size; i++) {
        free(sim->grid[i]);
    }
    free(sim->grid);
    sim->grid = new_grid;
    sim->step_count += 1;
}

int FluidSimulator_count_neighbors(FluidSimulator *sim, int x, int y) {
    int count = 0;
    int grid_size = sizeof(sim->grid) / sizeof(sim->grid[0]);
    for (int i = x - 1; i < x + 2; i++) {
        for (int j = y - 1; j < y + 2; j++) {
            if ((i != x || j != y) && 0 <= i && i < grid_size && 0 <= j && j < grid_size) {
                count += sim->grid[i][j];
            }
        }
    }
    return count;
}

void FluidSimulator_run(FluidSimulator *sim) {
    if (sim->step_count < sim->steps) {
        FluidSimulator_update(sim);
        FluidSimulator_run(sim);
    }
}

void main() {
    FluidSimulator *sim = FluidSimulator_init(10, 100);
    FluidSimulator_run(sim);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", sim->grid[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 10; i++) {
        free(sim->grid[i]);
    }
    free(sim->grid);
    free(sim);
}