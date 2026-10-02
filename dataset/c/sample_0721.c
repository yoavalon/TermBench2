#include <stdio.h>

int decay_reward(int reward, double factor, int threshold) {
    if (reward < threshold) {
        return 0;
    }
    return (int)(reward * factor);
}

int compute_reward(int initial, double factor, int steps, int threshold) {
    int reward = initial;
    for (int i = 0; i < steps; i++) {
        reward = decay_reward(reward, factor, threshold);
    }
    return reward;
}

int main() {
    int initial_reward = 100;
    double decay_factor = 0.9;
    int steps = 10;
    int threshold = 10;
    int final_reward = compute_reward(initial_reward, decay_factor, steps, threshold);
    printf("%d\n", final_reward);
    return 0;
}