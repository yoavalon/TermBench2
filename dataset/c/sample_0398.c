#include <stdio.h>
#include <math.h>

void main() {
    double reward_decay(int step) {
        return pow(0.99, step);
    }

    int step = 0;
    while (1) {
        printf("Step %d: Reward %.4f\n", step, reward_decay(step));
        step += 1;
    }
}