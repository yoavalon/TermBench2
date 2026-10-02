#include <stdio.h>
#include <string.h>

char* state_transition(char* state, char* input) {
    if (strcmp(state, "idle") == 0 && strcmp(input, "connect") == 0) {
        return "connecting";
    } else if (strcmp(state, "connecting") == 0 && strcmp(input, "acknowledged") == 0) {
        return "connected";
    } else if (strcmp(state, "connected") == 0 && strcmp(input, "disconnect") == 0) {
        return "disconnecting";
    } else if (strcmp(state, "disconnecting") == 0 && strcmp(input, "disconnected") == 0) {
        return "idle";
    }
    return state;
}

void process_inputs() {
    char* current_state = "idle";
    char* inputs[] = {"connect", "acknowledged", "disconnect", "disconnected"};
    while (1) {
        for (int i = 0; i < 4; i++) {
            current_state = state_transition(current_state, inputs[i]);
        }
    }
}

int main() {
    process_inputs();
    return 0;
}