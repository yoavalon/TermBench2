#include <stdio.h>
#include <stdlib.h>

double decay_reward(double reward, double decay_rate) {
    return reward * (1 - decay_rate);
}

void simulate_reward_decay() {
    double reward = 1.0;
    double decay_rate = 0.05;
    while (1) {
        reward = decay_reward(reward, decay_rate);
        printf("%f\n", reward);
    }
}

int main() {
    simulate_reward_decay();
    return 0;
}