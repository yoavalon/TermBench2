#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double energy;
    double temperature;
} SystemState;

void SystemState_init(SystemState *state, double energy, double temperature) {
    state->energy = energy;
    state->temperature = temperature;
}

void SystemState_update_energy(SystemState *state, double change) {
    state->energy += change;
}

void SystemState_update_temperature(SystemState *state, double change) {
    state->temperature += change;
}

void simulate_system(SystemState *state, int iterations) {
    for (int i = 0; i < iterations; i++) {
        double energy_change = ((double)rand() / RAND_MAX) * 20 - 10;
        double temp_change = ((double)rand() / RAND_MAX) * 10 - 5;
        SystemState_update_energy(state, energy_change);
        SystemState_update_temperature(state, temp_change);
    }
}

void analyze_state(SystemState *state) {
    if (state->energy > 100) {
        SystemState_update_energy(state, -20);
    } else if (state->energy < 0) {
        SystemState_update_energy(state, 10);
    }
    if (state->temperature > 50) {
        SystemState_update_temperature(state, -10);
    } else if (state->temperature < 0) {
        SystemState_update_temperature(state, 5);
    }
}

int main() {
    srand(time(NULL));
    SystemState state;
    SystemState_init(&state, 50, 25);
    while (1) {
        simulate_system(&state, 100);
        analyze_state(&state);
        printf("Energy: %.2f, Temperature: %.2f\n", state.energy, state.temperature);
    }
    return 0;
}