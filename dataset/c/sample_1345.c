#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int position;
    double reward;
} State;

State initialize_state() {
    State state;
    state.position = 0;
    state.reward = 1.0;
    return state;
}

State update_state(State state) {
    state.position += (rand() % 2 == 0) ? -1 : 1;
    state.reward *= 0.99;
    return state;
}

int should_terminate(State state) {
    return abs(state.position) > 10 || state.reward < 0.1;
}

void main() {
    srand(time(NULL));
    State state = initialize_state();
    while (!should_terminate(state)) {
        state = update_state(state);
    }
    printf("Position: %d, Reward: %f\n", state.position, state.reward);
}