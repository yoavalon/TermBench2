#include <stdio.h>

typedef struct {
    double temp;
    double pressure;
} SystemState;

void SystemState_update_state(SystemState *self, double new_temp, double new_pressure) {
    self->temp = new_temp;
    self->pressure = new_pressure;
}

typedef struct {
    SystemState *system;
    int iteration;
} SimulationController;

void SimulationController_run_simulation(SimulationController *self) {
    while (1) {
        self->iteration++;
        double new_temp, new_pressure;
        new_temp = self->system->temp + 0.001 * self->iteration % 10;
        new_pressure = self->system->pressure + 0.002 * self->iteration % 15;
        SystemState_update_state(self->system, new_temp, new_pressure);
        printf("Iteration %d: Temp = %.5f, Pressure = %.5f\n", self->iteration, self->system->temp, self->system->pressure);
    }
}

void SimulationController_init(SimulationController *self, SystemState *system) {
    self->system = system;
    self->iteration = 0;
}

void SystemState_init(SystemState *self, double temp, double pressure) {
    self->temp = temp;
    self->pressure = pressure;
}

int main() {
    double initial_temp = 300.0;
    double initial_pressure = 1.0;
    SystemState system;
    SystemState_init(&system, initial_temp, initial_pressure);
    SimulationController controller;
    SimulationController_init(&controller, &system);
    SimulationController_run_simulation(&controller);
    return 0;
}