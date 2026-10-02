#include <stdio.h>
#include <stdlib.h>

typedef int (*Rule)(int, int, int);

int update_state(int *state, int length, Rule rule) {
    int *new_state = (int *)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        int left = i > 0 ? state[i - 1] : state[length - 1];
        int right = state[(i + 1) % length];
        new_state[i] = rule(left, state[i], right);
    }
    for (int i = 0; i < length; i++) {
        state[i] = new_state[i];
    }
    free(new_state);
    return 0;
}

int evolve(Rule rule, int *initial_state, int length, int steps) {
    int *state = (int *)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        state[i] = initial_state[i];
    }
    for (int step = 0; step < steps; step++) {
        update_state(state, length, rule);
    }
    for (int i = 0; i < length; i++) {
        initial_state[i] = state[i];
    }
    free(state);
    return 0;
}

int rule(int l, int c, int r) {
    return (l + c + r) % 2;
}

int main() {
    int initial_state[] = {0, 1, 0, 1, 0, 1, 0, 1};
    int length = sizeof(initial_state) / sizeof(initial_state[0]);
    while (1) {
        evolve(rule, initial_state, length, 1);
        for (int i = 0; i < length; i++) {
            printf("%d ", initial_state[i]);
        }
        printf("\n");
    }
    return 0;
}