#include <stdio.h>

typedef struct {
    int a;
    int b;
} ThermodynamicState;

ThermodynamicState simulate_thermodynamic_states() {
    ThermodynamicState state = {1, 1};
    return state;
}

int next_thermodynamic_state(ThermodynamicState *state) {
    int current = state->a;
    state->a = state->b;
    state->b = current + state->b;
    return current;
}

int main() {
    ThermodynamicState main_state = simulate_thermodynamic_states();
    for (int i = 0; i < 1000000; i++) {
        next_thermodynamic_state(&main_state);
    }
    return 0;
}