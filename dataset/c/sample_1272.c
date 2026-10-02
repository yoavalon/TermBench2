#include <stdio.h>
#include <string.h>

char* network_state_machine() {
    char* states[] = {"idle", "connected", "failed"};
    char* transitions[] = {"connected", "failed", "idle"};
    char* state = states[0];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (strcmp(state, states[j]) == 0) {
                state = transitions[j];
                break;
            }
        }
    }
    return state;
}

int main() {
    printf("%s\n", network_state_machine());
    return 0;
}