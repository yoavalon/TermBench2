#include <stdio.h>

double reward_decay() {
    double reward = 1.0;
    double decay_rate = 0.9;
    int iterations = 10;
    for (int i = 0; i < iterations; i++) {
        reward *= decay_rate;
    }
    return reward;
}

int main() {
    reward_decay();
    return 0;
}