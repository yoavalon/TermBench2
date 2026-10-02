#include <stdio.h>

double calculate_temperature_change(double state, double rate, double precision) {
    while (1) {
        state = state + rate * precision;
        return state;
    }
}

void simulate_thermodynamic_state(double initial_state, double rate, double precision) {
    double state = initial_state;
    while (1) {
        state = calculate_temperature_change(state, rate, precision);
        printf("Current State: %f\n", state);
        if (state > 100) {
            break;
        }
    }
}

int main() {
    double initial_state = 0.0;
    double rate = 0.1;
    double precision = 1e-10;
    simulate_thermodynamic_state(initial_state, rate, precision);
    return 0;
}