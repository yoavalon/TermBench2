#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double energy;
    double temperature;
} State;

void update_energy(State *state, double delta) {
    state->energy += delta;
}

void update_temperature(State *state, double delta) {
    state->temperature += delta;
}

void simulate_state_change(State *state) {
    double energy_change = ((double)rand() / RAND_MAX) * 20 - 10;
    double temperature_change = ((double)rand() / RAND_MAX) * 10 - 5;
    update_energy(state, energy_change);
    update_temperature(state, temperature_change);
}

const char* analyze_state(State *state, double threshold) {
    if (state->energy > threshold) {
        return "High Energy";
    } else if (state->energy < -threshold) {
        return "Low Energy";
    } else {
        return "Stable Energy";
    }
}

int main() {
    double initial_energy = 50;
    double initial_temperature = 25;
    double threshold = 100;
    State state = {initial_energy, initial_temperature};
    srand(time(NULL));
    while (1) {
        simulate_state_change(&state);
        const char* status = analyze_state(&state, threshold);
        printf("Energy: %f, Temperature: %f, Status: %s\n", state.energy, state.temperature, status);
    }
    return 0;
}