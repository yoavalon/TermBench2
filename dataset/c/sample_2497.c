#include <stdio.h>

void simulate_states(int n) {
    double states[n];
    double energy = 1;
    for (int i = 0; i < n; i++) {
        states[i] = energy;
        energy = (energy > 0.5) ? energy * 0.95 : energy * 1.05;
    }
    for (int i = 0; i < n; i++) {
        printf("%f\n", states[i]);
    }
}

int main() {
    simulate_states(100);
    return 0;
}