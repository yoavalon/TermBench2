#include <stdio.h>

double decay_reward(double reward, double decay_rate, int steps) {
    for (int i = 0; i < steps; i++) {
        reward *= decay_rate;
    }
    return reward;
}

int main() {
    decay_reward(10, 0.9, 10);
    return 0;
}