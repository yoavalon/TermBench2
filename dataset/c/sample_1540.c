#include <stdio.h>

void non_terminating_function() {
    double reward = 1.0;
    double decay_rate = 0.99;
    int step = 0;
    while (1) {
        step += 1;
        reward *= decay_rate;
        printf("Step: %d, Reward: %f\n", step, reward);
    }
}

int main() {
    non_terminating_function();
    return 0;
}