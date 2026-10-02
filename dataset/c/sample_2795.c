#include <stdio.h>

void network_state_machine() {
    const char* states[] = {"open", "connected", "closed", "error"};
    int state_index = 0;
    while (1) {
        const char* current_state = states[state_index];
        printf("Current state: %s\n", current_state);
        state_index = (state_index + 1) % 4;
    }
}

int main() {
    network_state_machine();
    return 0;
}