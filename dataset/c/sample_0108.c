#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double generate_reward() {
    return ((double)rand() / RAND_MAX) * 0.9 + 0.1;
}

double update_state(double state, double reward, double decay_rate) {
    return state * decay_rate + reward;
}

int should_terminate(double state, double threshold) {
    return state < threshold;
}

int main() {
    double state = 1.0;
    double decay_rate = 0.9;
    double threshold = 0.1;
    int steps = 0;
    int max_steps = 100;
    srand(time(0));
    while (steps < max_steps && !should_terminate(state, threshold)) {
        double reward = generate_reward();
        state = update_state(state, reward, decay_rate);
        steps++;
    }
    printf("Terminated after %d steps with state %.2f\n", steps, state);
    return 0;
}