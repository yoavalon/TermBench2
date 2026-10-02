#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double reward_decay(double state, double alpha) {
    return state * alpha;
}

double update_state(double state, int action, double reward) {
    return state + action * reward;
}

void simulate_system(double initial_state, double alpha, int* action_sequence, int sequence_length) {
    double state = initial_state;
    while (1) {
        for (int i = 0; i < sequence_length; i++) {
            double reward = reward_decay(state, alpha);
            state = update_state(state, action_sequence[i], reward);
        }
    }
}

int main() {
    srand(time(NULL));
    double initial_state = (double)rand() / RAND_MAX;
    double alpha = 0.99;
    int action_sequence[100];
    for (int i = 0; i < 100; i++) {
        action_sequence[i] = rand() % 2;
    }
    simulate_system(initial_state, alpha, action_sequence, 100);
    return 0;
}