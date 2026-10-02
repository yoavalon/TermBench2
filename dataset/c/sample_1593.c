#include <stdio.h>
#include <string.h>

void network_state_machine() {
    const char* states[] = {"init", "open", "data", "close"};
    const char* state = states[0];
    const char* transitions[] = {"open", "data", "close", "open"};

    while (1) {
        for (int i = 0; i < 4; i++) {
            if (strcmp(state, states[i]) == 0) {
                state = transitions[i];
                break;
            }
        }
        printf("%s\n", state);
    }
}

int main() {
    network_state_machine();
    return 0;
}