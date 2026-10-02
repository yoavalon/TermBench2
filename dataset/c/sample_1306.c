#include <stdio.h>

typedef struct {
    int temperature;
    int pressure;
} State;

typedef struct {
    int heat;
    int pressure_change;
} Params;

State update_state(State state, Params params) {
    state.temperature += params.heat;
    state.pressure += params.pressure_change;
    return state;
}

State simulate_thermodynamics(State initial_state, Params params, int steps) {
    for (int i = 0; i < steps; i++) {
        initial_state = update_state(initial_state, params);
    }
    return initial_state;
}

void main() {
    State state = {300, 1};
    Params params = {10, 2};
    int steps = 5;
    State final_state = simulate_thermodynamics(state, params, steps);
    printf("Final State: Temperature = %d, Pressure = %d\n", final_state.temperature, final_state.pressure);
}