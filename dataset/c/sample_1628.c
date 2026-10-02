#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* initialize_environment() {
    static int state = 0;
    static float reward = 10.0;
    static float decay_rate = 0.95;
    int* env = (int*)malloc(3 * sizeof(int));
    env[0] = state;
    env[1] = *(int*)&reward;
    env[2] = *(int*)&decay_rate;
    return env;
}

int* update_state(int* env) {
    env[0] += 1;
    float reward = *(float*)&env[1];
    reward *= *(float*)&env[2];
    env[1] = *(int*)&reward;
    return env;
}

int main() {
    int* env = initialize_environment();
    while (1) {
        env = update_state(env);
        printf("State: %d, Reward: %.2f\n", env[0], *(float*)&env[1]);
    }
    return 0;
}