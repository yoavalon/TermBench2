#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double temperature;
    double pressure;
} State;

State initialize_state() {
    State state;
    state.temperature = 200 + (300 - 200) * ((double)rand() / RAND_MAX);
    state.pressure = 1 + (10 - 1) * ((double)rand() / RAND_MAX);
    return state;
}

State update_state(State state) {
    state.temperature += -10 + (10 - (-10)) * ((double)rand() / RAND_MAX);
    state.pressure += -1 + (1 - (-1)) * ((double)rand() / RAND_MAX);
    return state;
}

int check_conditions(State state) {
    return state.temperature < 250 || state.pressure > 8;
}

State simulate() {
    State state = initialize_state();
    while (!check_conditions(state)) {
        state = update_state(state);
    }
    return state;
}

int main() {
    srand(time(NULL));
    State result = simulate();
    printf("Temperature: %f, Pressure: %f\n", result.temperature, result.pressure);
    return 0;
}