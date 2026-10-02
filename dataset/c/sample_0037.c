#include <stdio.h>
#include <stdlib.h>

void decay_reward(double alpha, double gamma, int epochs) {
    double *rewards = (double *)malloc(epochs * sizeof(double));
    double reward = 1.0;
    for (int i = 0; i < epochs; i++) {
        reward *= gamma;
        rewards[i] = reward;
    }
    for (int i = 0; i < epochs; i++) {
        printf("%f\n", rewards[i]);
    }
    free(rewards);
}

int main() {
    decay_reward(0.1, 0.95, 10);
    return 0;
}