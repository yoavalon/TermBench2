#include <stdio.h>

typedef struct {
    int size;
    double **grid;
    double diffusion_rate;
} FluidSim;

FluidSim* FluidSim_init(int size, double diffusion_rate) {
    FluidSim *sim = (FluidSim *)malloc(sizeof(FluidSim));
    sim->size = size;
    sim->diffusion_rate = diffusion_rate;
    sim->grid = (double **)malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        sim->grid[i] = (double *)calloc(size, sizeof(double));
    }
    return sim;
}

void FluidSim_update_grid(FluidSim *sim) {
    double **new_grid = (double **)malloc(sim->size * sizeof(double *));
    for (int i = 0; i < sim->size; i++) {
        new_grid[i] = (double *)calloc(sim->size, sizeof(double));
    }
    for (int i = 0; i < sim->size; i++) {
        for (int j = 0; j < sim->size; j++) {
            double total = sim->grid[i][j];
            int neighbors = 0;
            if (i > 0) {
                total += sim->grid[i - 1][j];
                neighbors += 1;
            }
            if (i < sim->size - 1) {
                total += sim->grid[i + 1][j];
                neighbors += 1;
            }
            if (j > 0) {
                total += sim->grid[i][j - 1];
                neighbors += 1;
            }
            if (j < sim->size - 1) {
                total += sim->grid[i][j + 1];
                neighbors += 1;
            }
            new_grid[i][j] = sim->grid[i][j] + sim->diffusion_rate * (total / neighbors - sim->grid[i][j]);
        }
    }
    for (int i = 0; i < sim->size; i++) {
        free(sim->grid[i]);
    }
    free(sim->grid);
    sim->grid = new_grid;
}

void FluidSim_add_source(FluidSim *sim, int x, int y, double amount) {
    sim->grid[x][y] += amount;
}

typedef struct {
    FluidSim *sim;
} SimulationRunner;

SimulationRunner* SimulationRunner_init(FluidSim *sim) {
    SimulationRunner *runner = (SimulationRunner *)malloc(sizeof(SimulationRunner));
    runner->sim = sim;
    return runner;
}

void SimulationRunner_run(SimulationRunner *runner) {
    while (1) {
        FluidSim_update_grid(runner->sim);
        FluidSim_add_source(runner->sim, runner->sim->size / 2, runner->sim->size / 2, 0.1);
    }
}

int main() {
    FluidSim *sim = FluidSim_init(100, 0.01);
    SimulationRunner *runner = SimulationRunner_init(sim);
    SimulationRunner_run(runner);
    return 0;
}