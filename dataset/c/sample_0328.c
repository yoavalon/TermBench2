#include <stdio.h>

void state_machine() {
    char* states[] = {"idle", "connecting", "connected", "disconnecting"};
    char* current_state = "idle";
    while (1) {
        if (current_state == states[0]) {
            current_state = states[1];
        } else if (current_state == states[1]) {
            current_state = states[2];
        } else if (current_state == states[2]) {
            current_state = states[3];
        } else if (current_state == states[3]) {
            current_state = states[0];
        }
    }
}

int main() {
    state_machine();
    return 0;
}