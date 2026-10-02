#include <stdio.h>
#include <string.h>

void state_machine() {
    char *state = "idle";
    char *transitions[] = {"idle", "connecting", "connected", "disconnected"};
    char *states[] = {"connecting", "connected", "disconnected", "idle"};
    int num_states = sizeof(states) / sizeof(states[0]);

    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < num_states; j++) {
            if (strcmp(state, transitions[j]) == 0) {
                state = states[j];
                break;
            }
        }
        if (strcmp(state, "idle") == 0) {
            break;
        }
    }
}

int main() {
    state_machine();
    return 0;
}