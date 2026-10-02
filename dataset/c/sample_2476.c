#include <stdio.h>

int process_sequence(int sequence[], int length) {
    int state = 0;
    int transitions[4][2] = {
        {1, 2},
        {3, 0},
        {0, 3},
        {2, 1}
    };
    for (int i = 0; i < length; i++) {
        state = transitions[state][sequence[i]];
    }
    return state;
}

void main() {
    int sequence[] = {0, 1, 0, 1, 1, 0, 0};
    int result = process_sequence(sequence, 7);
    printf("%d\n", result);
}