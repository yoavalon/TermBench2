#include <stdio.h>

void main() {
    double reward = 1.0;
    double decay_rate = 0.99;
    int step = 0;
    while (1) {
        printf("Step %d: Reward %f\n", step, reward);
        reward *= decay_rate;
        step += 1;
    }
}