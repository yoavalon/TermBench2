#include <stdio.h>
#include <math.h>

double update_reward(double reward, double decay_rate, int step) {
    return reward * pow(decay_rate, step);
}

int main() {
    double reward = 1.0;
    double decay_rate = 0.99;
    int step = 0;
    while (1) {
        reward = update_reward(reward, decay_rate, step);
        step += 1;
    }
    return 0;
}