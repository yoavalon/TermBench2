#include <stdio.h>

typedef struct {
    double temp;
    double pressure;
    double volume;
} SimulationState;

void update_state(SimulationState *state, double delta_temp, double delta_pressure, double delta_volume) {
    state->temp += delta_temp;
    state->pressure += delta_pressure;
    state->volume += delta_volume;
}

typedef struct {
    double max_temp;
    double min_temp;
    double max_pressure;
    double min_pressure;
    double max_volume;
    double min_volume;
} BoundaryConditions;

int check_boundaries(BoundaryConditions *conditions, SimulationState *state) {
    if (state->temp > conditions->max_temp || state->temp < conditions->min_temp) {
        return 0;
    }
    if (state->pressure > conditions->max_pressure || state->pressure < conditions->min_pressure) {
        return 0;
    }
    if (state->volume > conditions->max_volume || state->volume < conditions->min_volume) {
        return 0;
    }
    return 1;
}

typedef struct {
    SimulationState state;
    BoundaryConditions boundary_conditions;
    double step_size;
} SimulationEngine;

void run_simulation(SimulationEngine *engine) {
    while (1) {
        update_state(&engine->state, engine->step_size, engine->step_size, engine->step_size);
        if (!check_boundaries(&engine->boundary_conditions, &engine->state)) {
            update_state(&engine->state, -engine->step_size, -engine->step_size, -engine->step_size);
        } else {
            printf("Temp: %.2f, Pressure: %.2f, Volume: %.2f\n", engine->state.temp, engine->state.pressure, engine->state.volume);
        }
    }
}

void main() {
    SimulationState initial_state = {300, 1, 10};
    BoundaryConditions boundary_conditions = {400, 200, 2, 0.5, 20, 5};
    SimulationEngine simulation_engine = {initial_state, boundary_conditions, 0.1};
    run_simulation(&simulation_engine);
}