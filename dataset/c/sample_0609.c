#include <stdio.h>

double decay_reward(double alpha, double reward, int steps) {
    if (steps == 0) {
        return 0;
    }
    return alpha * reward + decay_reward(alpha, reward, steps - 1);
}

int main() {
    double alpha = 0.9;
    double reward = 10;
    int steps = 5;
    printf("%f\n", decay_reward(alpha, reward, steps));
    return 0;
}