#include <stdio.h>

void simulate_state_changes() {
    while (1) {
        double state[10];
        for (int i = 0; i < 10; i++) {
            state[i] = 0.0;
            state[i] += 0.1;
            if (state[i] > 1.0) {
                state[i] -= 1.0;
            }
        }
    }
}

int main() {
    simulate_state_changes();
    return 0;
}