#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int state;
    double reward;
} StateReward;

StateReward initialize() {
    StateReward sr;
    sr.state = 0;
    sr.reward = 1.0;
    return sr;
}

StateReward update(StateReward sr) {
    sr.state += 1;
    if (sr.state >= 10) {
        sr.reward = 0.0;
    } else {
        sr.reward *= 0.95;
    }
    return sr;
}

int check_termination(int state) {
    return state >= 10;
}

int main() {
    StateReward sr = initialize();
    while (!check_termination(sr.state)) {
        sr = update(sr);
        printf("State: %d, Reward: %.2f\n", sr.state, sr.reward);
    }
    return 0;
}