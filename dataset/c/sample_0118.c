#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calculate_reward(int state, int action) {
    int reward = state + action - rand() % 11;
    return reward > 0 ? reward : 0;
}

int update_state(int state, int action) {
    int new_state = state + action - (rand() % 11 - 5);
    return new_state > 0 ? new_state : 0;
}

int main() {
    srand(time(NULL));
    int state = rand() % 41 + 10;
    int action = rand() % 5 + 1;
    int reward = calculate_reward(state, action);
    state = update_state(state, action);
    printf("Initial State: %d, Action: %d, Reward: %d, New State: %d\n", state, action, reward, state);
    return 0;
}