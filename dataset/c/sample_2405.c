#include <stdio.h>

double reward_decay(double alpha, double gamma, int steps) {
    double reward = 1;
    for (int i = 0; i < steps; i++) {
        reward *= alpha * gamma;
    }
    return reward;
}

int main() {
    double alpha = 0.5;
    double gamma = 0.9;
    int steps = 10;
    double result = reward_decay(alpha, gamma, steps);
    printf("%f\n", result);
    return 0;
}