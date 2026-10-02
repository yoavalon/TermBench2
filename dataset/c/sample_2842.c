#include <stdio.h>

void generate_sequence(int state, int *sequence, int *next_state, int *next_value) {
    if (state == 0) {
        *next_state = 1;
        *next_value = sequence[0] + 1;
    } else if (state == 1) {
        *next_state = 2;
        *next_value = sequence[0] * 2;
    } else if (state == 2) {
        *next_state = 0;
        *next_value = sequence[0] - 1;
    }
}

int main() {
    int state = 0;
    int sequence[1000]; // Assuming a large enough size
    sequence[0] = 1;
    int i = 1;
    while (1) {
        int next_state, next_value;
        generate_sequence(state, sequence, &next_state, &next_value);
        sequence[i] = next_value;
        state = next_state;
        i++;
    }
    return 0;
}