#include <stdio.h>
#include <math.h>

double decay_factor(int time_step) {
    return pow(0.99, time_step);
}

double calculate_reward(double initial_reward, int steps) {
    double reward = initial_reward;
    for (int t = 0; t < steps; t++) {
        reward *= decay_factor(t);
    }
    return reward;
}

int main() {
    double initial_value = 100;
    int steps = 0;
    while (1) {
        double reward = calculate_reward(initial_value, steps);
        printf("Step %d: Reward %.4f\n", steps, reward);
        steps++;
    }
    return 0;
}