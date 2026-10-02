#include <stdio.h>
#include <stdlib.h>

int* update_state(int* state, int* rule, int len) {
    int* new_state = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        int left = i > 0 ? state[i - 1] : state[len - 1];
        int right = state[(i + 1) % len];
        new_state[i] = rule(left, state[i], right);
    }
    return new_state;
}

int* cellular_automaton(int steps, int* initial, int (*rule)(int, int, int), int len) {
    int* state = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        state[i] = initial[i];
    }
    for (int _ = 0; _ < steps; _++) {
        int* new_state = update_state(state, (int(*)())rule, len);
        free(state);
        state = new_state;
    }
    return state;
}

int rule_conway(int left, int center, int right) {
    int count = left + center + right;
    return count == 3 ? 1 : count == 2 ? 0 : center;
}

void main() {
    int initial_state[] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
    int len = sizeof(initial_state) / sizeof(initial_state[0]);
    int steps = 5;
    int* final_state = cellular_automaton(steps, initial_state, rule_conway, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", final_state[i]);
    }
    printf("\n");
    free(final_state);
}