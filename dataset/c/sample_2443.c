#include <stdio.h>
#include <stdlib.h>

double* reward_decay(int epochs, double decay_rate) {
    double* rewards = (double*)malloc(epochs * sizeof(double));
    double current_reward = 1.0;
    for (int i = 0; i < epochs; i++) {
        rewards[i] = current_reward;
        current_reward *= decay_rate;
    }
    return rewards;
}

int main() {
    int epochs = 10;
    double decay_rate = 0.9;
    double* rewards = reward_decay(epochs, decay_rate);
    for (int i = 0; i < epochs; i++) {
        printf("%f ", rewards[i]);
    }
    free(rewards);
    return 0;
}