#include <stdio.h>

double compute_reward_decay(double initial_reward, double decay_rate, int time_steps) {
    double reward = initial_reward;
    for (int i = 0; i < time_steps; i++) {
        reward *= decay_rate;
    }
    return reward;
}

void simulate_data_mutation(double initial_data[], double decay_rate, int steps, double mutated_data[], int data_size) {
    for (int i = 0; i < data_size; i++) {
        mutated_data[i] = compute_reward_decay(initial_data[i], decay_rate, steps);
    }
}

int main() {
    double data[] = {100, 200, 300, 400, 500};
    double rate = 0.95;
    int steps = 10;
    double result[5];
    simulate_data_mutation(data, rate, steps, result, 5);
    for (int i = 0; i < 5; i++) {
        printf("%f ", result[i]);
    }
    return 0;
}