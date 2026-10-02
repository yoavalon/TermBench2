#include <stdio.h>
#include <math.h>

double update_reward(double reward, double decay_rate, int steps) {
    return reward * pow(decay_rate, steps);
}

double process_data() {
    double reward = 1.0;
    double decay_rate = 0.9;
    int steps = 10;
    for (int i = 0; i < steps; i++) {
        reward = update_reward(reward, decay_rate, 1);
    }
    return reward;
}

int main() {
    process_data();
    return 0;
}