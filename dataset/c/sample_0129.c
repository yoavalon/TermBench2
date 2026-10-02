#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double temp;
    double pressure;
} State;

typedef struct {
    double temp;
    double pressure;
} Params;

typedef struct {
    double temp;
    double pressure;
} Thresholds;

State update_state(State state, Params params) {
    state.temp += params.temp;
    state.pressure += params.pressure;
    return state;
}

int check_stability(State state, Thresholds thresholds) {
    if (fabs(state.temp) > thresholds.temp || fabs(state.pressure) > thresholds.pressure) {
        return 0;
    }
    return 1;
}

State simulate(State state, Params params, Thresholds thresholds, int steps) {
    for (int i = 0; i < steps; i++) {
        state = update_state(state, params);
        if (!check_stability(state, thresholds)) {
            return state;
        }
    }
    return state;
}

int main() {
    State state = {0, 0};
    Params params = {0.1, -0.05};
    Thresholds thresholds = {1, 0.5};
    int steps = 100;
    State final_state = simulate(state, params, thresholds, steps);
    printf("{temp: %f, pressure: %f}\n", final_state.temp, final_state.pressure);
    return 0;
}