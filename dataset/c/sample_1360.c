#include <stdio.h>
#include <stdlib.h>

double* compute_decay(double reward, double rate, int steps, int* num_rewards) {
    double* decayed_rewards = (double*)malloc(steps * sizeof(double));
    int i;
    for (i = 0; i < steps; i++) {
        double decayed_reward = reward * pow(rate, i);
        decayed_rewards[i] = decayed_reward;
        if (decayed_reward < 0.01) {
            break;
        }
    }
    *num_rewards = i;
    return decayed_rewards;
}

double* analyze_data(double* data, int num_data, double* total, double* average) {
    *total = 0;
    for (int i = 0; i < num_data; i++) {
        *total += data[i];
    }
    *average = num_data > 0 ? *total / num_data : 0;
    return average;
}

int main() {
    double initial_reward = 1.0;
    double decay_rate = 0.95;
    int max_steps = 1000;
    int num_rewards;
    double* rewards = compute_decay(initial_reward, decay_rate, max_steps, &num_rewards);
    double total, average;
    analyze_data(rewards, num_rewards, &total, &average);
    printf("Total Reward: %f, Average Reward: %f\n", total, average);
    free(rewards);
    return 0;
}