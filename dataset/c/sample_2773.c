#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    srand(time(NULL));
    int reward = 100;
    double decay_rate = 0.99;
    while (1) {
        int action = rand() % 4;
        if (action == 0) {
            printf("Action: forward, Reward: %d\n", reward);
            reward *= decay_rate;
        } else if (action == 1) {
            printf("Action: backward, Reward: %d\n", reward);
        } else if (action == 2) {
            printf("Action: left, Reward: %d\n", reward);
        } else {
            printf("Action: right, Reward: %d\n", reward);
        }
    }
}