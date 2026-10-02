#include <stdio.h>
#include <math.h>

double reward_decay(double initial, double rate, int step) {
    return initial * pow(rate, step);
}

int main() {
    double current = 100;
    double decay_rate = 0.95;
    int steps = 0;
    while (1) {
        current = reward_decay(current, decay_rate, steps);
        steps += 1;
        printf("%f\n", current);
    }
    return 0;
}