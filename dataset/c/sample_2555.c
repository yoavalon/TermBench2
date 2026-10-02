#include <stdio.h>

int update_state(int state, int delta) {
    return state + delta;
}

int* compute_sequence(int steps, int initial, int increment, int* result) {
    int current = initial;
    for (int i = 0; i < steps; i++) {
        result[i] = current;
        current = update_state(current, increment);
    }
    return result;
}

int main() {
    int steps = 10;
    int initial = 0;
    int increment = 1;
    int sequence[steps];
    compute_sequence(steps, initial, increment, sequence);
    for (int i = 0; i < steps; i++) {
        printf("%d ", sequence[i]);
    }
    return 0;
}