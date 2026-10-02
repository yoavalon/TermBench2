#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void simulate_reward_decay() {
    double state = 1.0;
    double gamma = 0.99;
    while (1) {
        double reward = (double)rand() / RAND_MAX * state;
        state *= gamma;
        printf("Reward: %f, State: %f\n", reward, state);
    }
}

int main() {
    srand(time(NULL));
    simulate_reward_decay();
    return 0;
}