#include <stdio.h>

typedef struct {
    double temperature;
    double pressure;
    double energy;
} State;

State initialize_system() {
    State state = {300, 1, 500};
    return state;
}

State update_state(State state, int time_step) {
    state.temperature += 0.1 * time_step;
    state.pressure += 0.01 * time_step;
    state.energy -= 10 * time_step;
    return state;
}

int check_termination(State state) {
    return state.energy <= 0;
}

State simulate() {
    State state = initialize_system();
    int time_step = 1;
    while (!check_termination(state)) {
        state = update_state(state, time_step);
    }
    return state;
}

int main() {
    State final_state = simulate();
    printf("Final state: Temperature = %f, Pressure = %f, Energy = %f\n", final_state.temperature, final_state.pressure, final_state.energy);
    return 0;
}