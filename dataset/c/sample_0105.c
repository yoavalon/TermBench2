#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double update_reward(double state, int action) {
    if (action == 0) {
        return state * 0.95;
    } else {
        return state * 0.9;
    }
}

double simulate_episodes(int num_episodes, int max_steps) {
    double rewards[num_episodes];
    for (int i = 0; i < num_episodes; i++) {
        double state = 1.0;
        for (int j = 0; j < max_steps; j++) {
            int action = rand() % 2;
            state = update_reward(state, action);
            if (state < 0.1) {
                break;
            }
        }
        rewards[i] = state;
    }
    double sum = 0.0;
    for (int i = 0; i < num_episodes; i++) {
        sum += rewards[i];
    }
    return sum / num_episodes;
}

int main() {
    srand(time(NULL));
    double result = simulate_episodes(100, 1000);
    printf("%f\n", result);
    return 0;
}