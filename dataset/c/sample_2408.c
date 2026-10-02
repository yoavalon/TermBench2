#include <stdio.h>

void simulate_decay(int steps, double decay_rate, double initial_value, double results[]) {
    double value = initial_value;
    for (int i = 0; i < steps; i++) {
        results[i] = value;
        value *= decay_rate;
    }
}

int main() {
    int steps = 10;
    double decay_rate = 0.9;
    double initial_value = 100;
    double result[steps];
    simulate_decay(steps, decay_rate, initial_value, result);
    for (int i = 0; i < steps; i++) {
        printf("%f ", result[i]);
    }
    return 0;
}