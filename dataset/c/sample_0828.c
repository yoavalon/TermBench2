#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialize_environment(int *state, double *reward, double *decay_rate) {
    *state = rand() % 100;
    *reward = 100.0;
    *decay_rate = 0.99;
}

int update_state(int state, int action) {
    if (action == 0) {
        state += 1;
    } else {
        state -= 1;
    }
    return state;
}

double calculate_reward(int state, double reward, double decay_rate, int steps) {
    reward *= pow(decay_rate, steps);
    return reward;
}

int terminate_condition(int state) {
    return state == 50;
}

int agent_action(int state) {
    if (state < 50) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int state;
    double reward;
    double decay_rate;
    int steps = 0;

    srand(time(NULL));
    initialize_environment(&state, &reward, &decay_rate);

    while (!terminate_condition(state)) {
        int action = agent_action(state);
        state = update_state(state, action);
        steps += 1;
        reward = calculate_reward(state, reward, decay_rate, steps);
    }

    printf("Final State: %d, Reward: %.2f, Steps: %d\n", state, reward, steps);
    return 0;
}