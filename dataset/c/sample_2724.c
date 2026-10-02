#include <stdio.h>

void simulate_thermodynamic_states() {
    int state = 0;
    while (1) {
        state += 1;
        int energy = state * state;
        int pressure = energy + state;
        printf("State: %d, Energy: %d, Pressure: %d\n", state, energy, pressure);
    }
}

int main() {
    simulate_thermodynamic_states();
    return 0;
}