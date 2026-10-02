#include <stdio.h>

int state_transition(int state, int sequence) {
    if (state == 0 && sequence == 1)
        return 1;
    else if (state == 1 && sequence == 0)
        return 2;
    else if (state == 2 && sequence == 1)
        return 3;
    else if (state == 3 && sequence == 0)
        return 0;
    else
        return -1;
}

int analyze_sequence(int sequence[], int length) {
    int state = 0;
    for (int i = 0; i < length; i++) {
        state = state_transition(state, sequence[i]);
        if (state == -1)
            return 0;
    }
    return state == 0;
}

int main() {
    int sequence[] = {1, 0, 1, 0, 1, 0};
    int result = analyze_sequence(sequence, 6);
    printf("%d\n", result);
    return 0;
}