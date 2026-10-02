#include <stdio.h>

typedef struct {
    double temperature;
    double pressure;
} ThermodynamicState;

typedef struct {
    double max_temp;
    double min_temp;
    double max_press;
    double min_press;
} BoundaryConditions;

void update_state(ThermodynamicState *state, double delta_temp, double delta_press) {
    state->temperature += delta_temp;
    state->pressure += delta_press;
}

void check_boundaries(BoundaryConditions *conditions, ThermodynamicState *state) {
    if (state->temperature > conditions->max_temp) {
        state->temperature = conditions->max_temp;
    } else if (state->temperature < conditions->min_temp) {
        state->temperature = conditions->min_temp;
    }
    if (state->pressure > conditions->max_press) {
        state->pressure = conditions->max_press;
    } else if (state->pressure < conditions->min_press) {
        state->pressure = conditions->min_press;
    }
}

void simulate(ThermodynamicState *state, BoundaryConditions *conditions) {
    while (1) {
        double delta_temp = 1.5;
        double delta_press = -0.5;
        update_state(state, delta_temp, delta_press);
        check_boundaries(conditions, state);
    }
}

int main() {
    double initial_temp = 300;
    double initial_press = 1.0;
    double max_temp = 500;
    double min_temp = 200;
    double max_press = 2.0;
    double min_press = 0.5;
    ThermodynamicState state = {initial_temp, initial_press};
    BoundaryConditions conditions = {max_temp, min_temp, max_press, min_press};
    simulate(&state, &conditions);
    return 0;
}