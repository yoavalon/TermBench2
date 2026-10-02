#include <stdio.h>

double decay_reward(double initial_value, double decay_rate, int steps) {
    for (int i = 0; i < steps; i++) {
        initial_value *= decay_rate;
    }
    return initial_value;
}

int main() {
    double result = decay_reward(10.0, 0.9, 100);
    printf("%f\n", result);
    return 0;
}