#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double **grid;
    int size;
} FluidSimulator;

typedef struct {
    FluidSimulator *simulator;
} FluidController;

void FluidSimulator_init(FluidSimulator *self, int size) {
    self->size = size;
    self->grid = (double **)malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        self->grid[i] = (double *)calloc(size, sizeof(double));
    }
}

void FluidSimulator_update(FluidSimulator *self) {
    double **new_grid = (double **)malloc(self->size * sizeof(double *));
    for (int i = 0; i < self->size; i++) {
        new_grid[i] = (double *)calloc(self->size, sizeof(double));
    }
    for (int i = 0; i < self->size; i++) {
        for (int j = 0; j < self->size; j++) {
            new_grid[i][j] = self->grid[i][j] + FluidSimulator_calculate_flow(self, i, j);
        }
    }
    for (int i = 0; i < self->size; i++) {
        free(self->grid[i]);
    }
    free(self->grid);
    self->grid = new_grid;
}

double FluidSimulator_calculate_flow(FluidSimulator *self, int x, int y) {
    double flow = 0.0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < self->size && ny >= 0 && ny < self->size) {
                flow += self->grid[nx][ny] * 0.1;
            }
        }
    }
    return flow;
}

void FluidController_init(FluidController *self, FluidSimulator *simulator) {
    self->simulator = simulator;
}

void FluidController_run(FluidController *self) {
    while (1) {
        FluidSimulator_update(self->simulator);
    }
}

int main() {
    int size = 10;
    FluidSimulator simulator;
    FluidSimulator_init(&simulator, size);
    FluidController controller;
    FluidController_init(&controller, &simulator);
    FluidController_run(&controller);
    return 0;
}