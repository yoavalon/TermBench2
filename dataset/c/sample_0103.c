#include <stdio.h>

struct State {
    double temperature;
    double energy;
};

double compute_temperature_change(double initial_temp, double final_temp, double rate) {
    double change = (final_temp - initial_temp) * rate;
    return change;
}

struct State update_state(struct State state, double change) {
    state.temperature += change;
    state.energy += change * 1000;
    return state;
}

struct State simulate_state(double initial_temp, double final_temp, double rate, int steps) {
    struct State state = {initial_temp, 0};
    for (int i = 0; i < steps; i++) {
        double change = compute_temperature_change(state.temperature, final_temp, rate);
        state = update_state(state, change);
    }
    return state;
}

int main() {
    double initial_temp = 20;
    double final_temp = 100;
    double rate = 0.1;
    int steps = 10;
    struct State result = simulate_state(initial_temp, final_temp, rate, steps);
    printf("Temperature: %f, Energy: %f\n", result.temperature, result.energy);
    return 0;
}