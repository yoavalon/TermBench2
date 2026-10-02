#include <stdio.h>

void state_machine() {
    int states[] = {0, 1, 2};
    int state = states[0];
    int transitions[3][2] = {{0, 1}, {1, 0}, {0, 2}};
    while (1) {
        int action = transitions[state][0];
        state = transitions[action][1];
    }
}

int main() {
    state_machine();
    return 0;
}