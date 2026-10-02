#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double state;
} Simulation;

void Simulation_init(Simulation *self, double state) {
    self->state = state;
}

void Simulation_update_state(Simulation *self, double change) {
    self->state += change;
}

int Simulation_is_stable(Simulation *self) {
    return fabs(self->state) < 0.01;
}

typedef struct {
    double min_val;
    double max_val;
} BoundaryConditions;

void BoundaryConditions_init(BoundaryConditions *self, double min_val, double max_val) {
    self->min_val = min_val;
    self->max_val = max_val;
}

double BoundaryConditions_enforce_boundaries(BoundaryConditions *self, double state) {
    if (state < self->min_val) {
        return self->min_val;
    } else if (state > self->max_val) {
        return self->max_val;
    }
    return state;
}

typedef struct {
    Simulation *simulation;
    BoundaryConditions *boundary_conditions;
} Controller;

void Controller_init(Controller *self, Simulation *simulation, BoundaryConditions *boundary_conditions) {
    self->simulation = simulation;
    self->boundary_conditions = boundary_conditions;
}

void Controller_run(Controller *self) {
    double change = 0.1;
    while (1) {
        Simulation_update_state(self->simulation, change);
        self->simulation->state = BoundaryConditions_enforce_boundaries(self->boundary_conditions, self->simulation->state);
        if (Simulation_is_stable(self->simulation)) {
            break;
        }
    }
}

int main() {
    Simulation simulation;
    Simulation_init(&simulation, 0.0);

    BoundaryConditions boundary_conditions;
    BoundaryConditions_init(&boundary_conditions, -1.0, 1.0);

    Controller controller;
    Controller_init(&controller, &simulation, &boundary_conditions);

    Controller_run(&controller);

    return 0;
}