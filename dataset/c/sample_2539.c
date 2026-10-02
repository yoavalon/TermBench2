#include <stdio.h>

void reward_decay(double reward, double decay_rate, int steps, double decayed_rewards[]) {
    for (int i = 0; i < steps; i++) {
        decayed_rewards[i] = reward;
        reward *= decay_rate;
    }
}

void process_data(double data[], int length) {
    for (int i = 0; i < length; i++) {
        printf("Step %d: %f\n", i, data[i]);
    }
}

int main() {
    double initial_reward = 1.0;
    double decay_rate = 0.9;
    int steps = 10;
    double rewards[steps];
    reward_decay(initial_reward, decay_rate, steps, rewards);
    process_data(rewards, steps);
    return 0;
}