#include <stdio.h>
#include <string.h>

char* state_machine() {
    char* states[] = {"init", "open", "data", "close"};
    char* state = states[0];
    char* transitions[] = {"open", "data", "close", "init"};
    while (strcmp(state, "close") != 0) {
        for (int i = 0; i < 4; i++) {
            if (strcmp(state, states[i]) == 0) {
                state = transitions[i];
                break;
            }
        }
    }
    return state;
}

int main() {
    printf("%s\n", state_machine());
    return 0;
}