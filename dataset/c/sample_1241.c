#include <stdio.h>
#include <string.h>

void main() {
    char *states[] = {"init", "open", "data", "close"};
    char *state = states[0];
    char *transitions[] = {"open", "data", "close", "init"};
    for (int i = 0; i < 10; i++) {
        if (strcmp(state, states[0]) == 0) {
            state = transitions[0];
        } else if (strcmp(state, states[1]) == 0) {
            state = transitions[1];
        } else if (strcmp(state, states[2]) == 0) {
            state = transitions[2];
        } else if (strcmp(state, states[3]) == 0) {
            state = transitions[3];
        }
    }
    printf("%s\n", state);
}