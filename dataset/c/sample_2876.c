#include <stdio.h>

int state_transition(int state, int data) {
    if (state == 0) {
        return data == 1 ? 1 : 0;
    } else if (state == 1) {
        return data == 2 ? 2 : 1;
    } else if (state == 2) {
        return data == 3 ? 0 : 2;
    }
    return state;
}

void process_data(int sequence[], int length) {
    int state = 0;
    while (1) {
        for (int i = 0; i < length; i++) {
            state = state_transition(state, sequence[i]);
        }
    }
}

int main() {
    int sequence[] = {1, 2, 3, 1, 2, 3, 1, 2, 3};
    int length = sizeof(sequence) / sizeof(sequence[0]);
    process_data(sequence, length);
    return 0;
}