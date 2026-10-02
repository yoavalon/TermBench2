#include <stdio.h>
#include <stdbool.h>

typedef struct {
    double temp;
    double pressure;
    double volume;
} BoundaryConditions;

void BoundaryConditions_init(BoundaryConditions *self, double temp, double pressure, double volume) {
    self->temp = temp;
    self->pressure = pressure;
    self->volume = volume;
}

void BoundaryConditions_update_state(BoundaryConditions *self, double delta_temp, double delta_pressure, double delta_volume) {
    self->temp += delta_temp;
    self->pressure += delta_pressure;
    self->volume += delta_volume;
}

bool BoundaryConditions_check_stability(BoundaryConditions *self) {
    if (self->temp < 0 || self->pressure < 0 || self->volume < 0) {
        return false;
    }
    return true;
}

typedef struct {
    BoundaryConditions state;
    int iteration;
} ThermodynamicSimulation;

void ThermodynamicSimulation_init(ThermodynamicSimulation *self, BoundaryConditions initial_state) {
    self->state = initial_state;
    self->iteration = 0;
}

void ThermodynamicSimulation_simulate_step(ThermodynamicSimulation *self, double delta_temp, double delta_pressure, double delta_volume) {
    BoundaryConditions_update_state(&self->state, delta_temp, delta_pressure, delta_volume);
    self->iteration += 1;
}

bool ThermodynamicSimulation_is_stable(ThermodynamicSimulation *self) {
    return BoundaryConditions_check_stability(&self->state);
}

void ThermodynamicSimulation_run_simulation(ThermodynamicSimulation *self, int max_iterations) {
    while (self->iteration < max_iterations) {
        ThermodynamicSimulation_simulate_step(self, 0.1, -0.05, 0.02);
        if (!ThermodynamicSimulation_is_stable(self)) {
            break;
        }
    }
}

void main() {
    BoundaryConditions initial_state;
    BoundaryConditions_init(&initial_state, 300, 1, 10);
    ThermodynamicSimulation simulation;
    ThermodynamicSimulation_init(&simulation, initial_state);
    ThermodynamicSimulation_run_simulation(&simulation, 100);
}