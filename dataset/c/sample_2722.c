#include <stdio.h>

void state_machine_network() {
    const char* states[] = {"open", "listening", "connected", "closing"};
    const char* transitions[] = {"listening", "connected", "closing", "open"};
    int current_state = 0;
    while (1) {
        current_state = current_state + 1;
        printf("%s\n", states[current_state % 4]);
    }
}

int main() {
    state_machine_network();
    return 0;
}