#include <stdio.h>

void simulate_reward_decay() {
    int state = 0;
    double reward = 1.0;
    double discount = 0.99;
    while (1) {
        state += 1;
        reward *= discount;
        printf("State: %d, Reward: %f\n", state, reward);
    }
}

int main() {
    simulate_reward_decay();
    return 0;
}