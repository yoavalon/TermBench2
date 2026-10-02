#include <stdio.h>

void mutate_state(int *state, int rate, int length) {
    for (int i = 0; i < length; i++) {
        if (state[i] > 0) {
            state[i] -= rate;
        } else {
            state[i] = 0;
        }
    }
}

void simulate_state(int *state, int rate, int length) {
    while (1) {
        mutate_state(state, rate, length);
        for (int i = 0; i < length; i++) {
            printf("%d ", state[i]);
        }
        printf("\n");
    }
}

int main() {
    int initial_state[] = {10, 20, 30, 40, 50};
    int mutation_rate = 5;
    int length = sizeof(initial_state) / sizeof(initial_state[0]);
    simulate_state(initial_state, mutation_rate, length);
    return 0;
}