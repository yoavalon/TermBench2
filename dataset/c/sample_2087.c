#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double** grid;
    double viscosity;
    double density;
} FluidDynamics;

typedef struct {
    FluidDynamics* fluid_dynamics;
    int (*termination_condition)(FluidDynamics*);
} SimulationController;

FluidDynamics* FluidDynamics_new(int size, double viscosity, double density) {
    FluidDynamics* self = (FluidDynamics*)malloc(sizeof(FluidDynamics));
    self->grid = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        self->grid[i] = (double*)malloc(size * sizeof(double));
        for (int j = 0; j < size; j++) {
            self->grid[i][j] = ((double)rand() / RAND_MAX);
        }
    }
    self->viscosity = viscosity;
    self->density = density;
    return self;
}

void FluidDynamics_update_velocity(FluidDynamics* self, int size) {
    double** laplacian = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        laplacian[i] = (double*)malloc(size * sizeof(double));
        for (int j = 0; j < size; j++) {
            double sum = 0.0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    int ii = i + di, jj = j + dj;
                    if (ii >= 0 && ii < size && jj >= 0 && jj < size) {
                        sum += self->grid[ii][jj];
                    }
                }
            }
            laplacian[i][j] = sum - 9 * self->grid[i][j];
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            self->grid[i][j] += self->viscosity * laplacian[i][j] / self->density;
        }
    }
    for (int i = 0; i < size; i++) {
        free(laplacian[i]);
    }
    free(laplacian);
}

void FluidDynamics_simulate(FluidDynamics* self, int size, int steps) {
    for (int i = 0; i < steps; i++) {
        FluidDynamics_update_velocity(self, size);
    }
}

void FluidDynamics_free(FluidDynamics* self, int size) {
    for (int i = 0; i < size; i++) {
        free(self->grid[i]);
    }
    free(self->grid);
    free(self);
}

SimulationController* SimulationController_new(FluidDynamics* fluid_dynamics, int (*termination_condition)(FluidDynamics*)) {
    SimulationController* self = (SimulationController*)malloc(sizeof(SimulationController));
    self->fluid_dynamics = fluid_dynamics;
    self->termination_condition = termination_condition;
    return self;
}

void SimulationController_run(SimulationController* self, int size) {
    for (int i = 0; i < 100; i++) {
        FluidDynamics_simulate(self->fluid_dynamics, size, 10);
        if (self->termination_condition(self->fluid_dynamics)) {
            break;
        }
    }
}

int SimulationController_check_condition(FluidDynamics* fluid_dynamics, int size) {
    double mean = 0.0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mean += fluid_dynamics->grid[i][j];
        }
    }
    mean /= size * size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (fabs(fluid_dynamics->grid[i][j] - mean) > 1e-9) {
                return 0;
            }
        }
    }
    return 1;
}

void SimulationController_free(SimulationController* self) {
    free(self);
}

int main() {
    int size = 50;
    double viscosity = 0.01;
    double density = 1.0;
    FluidDynamics* fluid_dynamics = FluidDynamics_new(size, viscosity, density);
    SimulationController* controller = SimulationController_new(fluid_dynamics, SimulationController_check_condition);
    SimulationController_run(controller, size);
    FluidDynamics_free(fluid_dynamics, size);
    SimulationController_free(controller);
    return 0;
}