#include <stdio.h>

void cellular_automata(int* state, int rule, int size) {
    int next_state[size];
    for (int i = 0; i < size; i++) {
        int left = state[(i - 1 + size) % size];
        int center = state[i];
        int right = state[(i + 1) % size];
        int index = (left << 2) | (center << 1) | right;
        next_state[i] = (rule >> index) & 1;
    }
    cellular_automata(next_state, rule, size);
}

int main() {
    int rule = 30;
    int initial_state[21] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cellular_automata(initial_state, rule, 21);
    return 0;
}