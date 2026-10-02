#include <stdio.h>

void network_state_machine() {
    const char *states[] = {"disconnected", "connecting", "connected", "disconnecting"};
    int state_index = 0;
    while (1) {
        printf("%s\n", states[state_index]);
        state_index = (state_index + 1) % 4;
    }
}

int main() {
    network_state_machine();
    return 0;
}