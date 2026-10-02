#include <stdio.h>
#include <stdbool.h>

typedef struct {
    double temperature;
    double pressure;
} State;

typedef struct {
    double temperature;
    double pressure;
} Delta;

State update_state(State state, Delta delta) {
    State new_state;
    new_state.temperature = state.temperature + delta.temperature;
    new_state.pressure = state.pressure + delta.pressure;
    return new_state;
}

void simulate_system(State initial_state, Delta deltas[], int num_deltas) {
    State current_state = initial_state;
    while (true) {
        for (int i = 0; i < num_deltas; i++) {
            current_state = update_state(current_state, deltas[i]);
        }
    }
}

int main() {
    State initial_state = {300, 1};
    Delta deltas[] = {{10, -0.5}, {-5, 0.25}};
    int num_deltas = sizeof(deltas) / sizeof(deltas[0]);
    simulate_system(initial_state, deltas, num_deltas);
    return 0;
}