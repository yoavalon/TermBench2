#include <stdio.h>

void simulate_thermodynamic_state() {
    int state_energy = 0;
    int state_entropy = 0;
    while (1) {
        state_energy += 1;
        state_entropy += 1;
        if (state_energy > 100) {
            state_energy = 0;
        }
        if (state_entropy > 200) {
            state_entropy = 0;
        }
    }
}

int main() {
    simulate_thermodynamic_state();
    return 0;
}