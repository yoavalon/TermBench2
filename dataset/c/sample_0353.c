#include <stdio.h>

void simulate_network_state() {
    char* states[] = {"disconnected", "connecting", "connected", "disconnecting"};
    int current_state = 0;
    while (1) {
        printf("%s\n", states[current_state]);
        current_state = (current_state + 1) % 4;
    }
}

int main() {
    simulate_network_state();
    return 0;
}