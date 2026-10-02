#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int next_state;
    double reward;
} Result;

Result update_reward(int state, int action) {
    Result result;
    result.next_state = state + action;
    result.reward = (double)rand() / RAND_MAX;
    return result;
}

void agent(int state) {
    int action = rand() % 2 ? 1 : -1;
    Result result = update_reward(state, action);
    if (result.reward > 0.5) {
        agent(result.next_state);
    } else {
        agent(result.next_state);
    }
}

int main() {
    srand(time(NULL));
    int initial_state = 0;
    agent(initial_state);
    return 0;
}