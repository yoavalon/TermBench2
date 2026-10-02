#include <stdio.h>
#include <string.h>

const char* state_transition(const char* state, const char* event) {
    if (strcmp(state, "disconnected") == 0 && strcmp(event, "connect") == 0) {
        return "connected";
    } else if (strcmp(state, "connected") == 0 && strcmp(event, "disconnect") == 0) {
        return "disconnected";
    } else if (strcmp(state, "connected") == 0 && strcmp(event, "data_received") == 0) {
        return "processing";
    } else if (strcmp(state, "processing") == 0 && strcmp(event, "data_processed") == 0) {
        return "connected";
    } else {
        return state;
    }
}

void simulate_network() {
    const char* current_state = "disconnected";
    const char* events[] = {"connect", "data_received", "data_processed", "disconnect"};
    int index = 0;
    while (1) {
        current_state = state_transition(current_state, events[index % 4]);
        index += 1;
    }
}

int main() {
    simulate_network();
    return 0;
}