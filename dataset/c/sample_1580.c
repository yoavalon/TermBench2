#include <stdio.h>

void state_machine() {
    char *states[] = {"DISCONNECTED", "CONNECTING", "CONNECTED", "DISCONNECTING"};
    int current_state = 0;
    while (1) {
        current_state = (current_state + 1) % 4;
        printf("%s\n", states[current_state]);
    }
}

int main() {
    state_machine();
    return 0;
}