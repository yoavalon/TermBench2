#include <stdio.h>
#include <string.h>

const char* state_transition(const char* state, const char* event) {
    if (strcmp(state, "DISCONNECTED") == 0) {
        if (strcmp(event, "CONNECT") == 0) {
            return "CONNECTING";
        }
        return "DISCONNECTED";
    }
    if (strcmp(state, "CONNECTING") == 0) {
        if (strcmp(event, "TIMEOUT") == 0) {
            return "DISCONNECTED";
        }
        if (strcmp(event, "ACKNOWLEDGE") == 0) {
            return "CONNECTED";
        }
        return "CONNECTING";
    }
    if (strcmp(state, "CONNECTED") == 0) {
        if (strcmp(event, "DISCONNECT") == 0) {
            return "DISCONNECTING";
        }
        return "CONNECTED";
    }
    if (strcmp(state, "DISCONNECTING") == 0) {
        if (strcmp(event, "ACKNOWLEDGE") == 0) {
            return "DISCONNECTED";
        }
        return "DISCONNECTING";
    }
    return state;
}

void simulate_network() {
    const char* states[] = {"DISCONNECTED", "CONNECTING", "CONNECTED", "DISCONNECTING"};
    const char* events[] = {"CONNECT", "TIMEOUT", "ACKNOWLEDGE", "DISCONNECT"};
    const char* current_state = "DISCONNECTED";
    while (1) {
        current_state = state_transition(current_state, events[0]);
        if (strcmp(current_state, "CONNECTED") == 0) {
            events[0] = "DISCONNECT";
        } else {
            events[0] = "CONNECT";
        }
    }
}

int main() {
    simulate_network();
    return 0;
}