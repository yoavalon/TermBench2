#include <stdio.h>

double reward_decay(double current, double rate, double threshold) {
    if (current <= threshold) {
        return current;
    }
    return reward_decay(current * rate, rate, threshold);
}

void calculate_discounted_rewards(double initial, double rate, double threshold, double rewards[], int *size) {
    while (initial > threshold) {
        rewards[*size] = initial;
        (*size)++;
        initial = initial * rate;
    }
    rewards[*size] = initial;
    (*size)++;
}

int main() {
    double initial = 100;
    double rate = 0.9;
    double threshold = 10;
    double rewards[100];
    int size = 0;

    calculate_discounted_rewards(initial, rate, threshold, rewards, &size);

    for (int i = 0; i < size; i++) {
        printf("%.2f ", rewards[i]);
    }
    printf("\n");

    return 0;
}