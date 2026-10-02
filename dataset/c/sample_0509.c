c
#include <stdio.h>

typedef struct {
    double temp;
    double pressure;
    double volume;
} SystemState;

void SystemState_update(SystemState *self, double temp_change, double pressure_change, double volume_change) {
    self->temp += temp_change;
    self->pressure += pressure_change;
    self->volume += volume_change;
}

typedef struct {
    SystemState *state;
    int condition_count;
    void (*conditions[10])(SystemState *);
} Simulation;

void Simulation_add_condition(Simulation *self, void (*condition)(SystemState *)) {
    self->conditions[self->condition_count++] = condition;
}

void Simulation_run(Simulation *self) {
    while (1) {
        for (int i = 0; i < self->condition_count; i++) {
            self->conditions[i](self->state);
        }
    }
}

typedef struct {
    double threshold;
    void (*effect)(SystemState *);
} BoundaryCondition;

void BoundaryCondition_call(BoundaryCondition *self, SystemState *state) {
    if (state->temp > self->threshold) {
        self->effect(state);
    }
}

void apply_effect(SystemState *state) {
    SystemState_update(state, -10, 5, -2);
}

void main() {
    SystemState initial_state = {300, 101325, 0.5};
    Simulation simulation = {&initial_state, 0};
    BoundaryCondition condition = {350, apply_effect};
    Simulation_add_condition(&simulation, (void (*)(SystemState *))BoundaryCondition_call);
    Simulation_run(&simulation);
}