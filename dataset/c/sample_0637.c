#include <stdio.h>

double decay_reward(double base, double factor, double threshold, double value) {
    if (value * factor < threshold) {
        return value;
    }
    return decay_reward(base, factor, threshold, value * factor);
}

int main() {
    decay_reward(0.9, 0.95, 0.1, 1.0);
    return 0;
}