#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int initialize_environment() {
    return rand() % 10;
}

int update_state(int state, int action) {
    return (state + action) % 10;
}

double calculate_reward(int state) {
    return sin(state);
}

double decay_reward(double reward, int step) {
    return reward * pow(0.9, step);
}

void main() {
    srand(time(0));
    int state = initialize_environment();
    int step = 0;
    while (1) {
        int action = rand() % 3;
        state = update_state(state, action);
        double reward = calculate_reward(state);
        reward = decay_reward(reward, step);
        step += 1;
    }
}