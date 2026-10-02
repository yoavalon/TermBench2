#include <stdio.h>
#include <string.h>

char* process_event(char* state, char* event) {
    if (strcmp(state, "connected") == 0) {
        if (strcmp(event, "data_received") == 0) {
            return "data_processing";
        } else if (strcmp(event, "connection_lost") == 0) {
            return "disconnected";
        }
    } else if (strcmp(state, "disconnected") == 0) {
        if (strcmp(event, "reconnect_attempt") == 0) {
            return "connecting";
        }
    } else if (strcmp(state, "connecting") == 0) {
        if (strcmp(event, "connection_established") == 0) {
            return "connected";
        }
    }
    return state;
}

void state_machine() {
    char* state = "disconnected";
    while (1) {
        char* event = strcmp(state, "disconnected") == 0 ? "reconnect_attempt" : "data_received";
        state = process_event(state, event);
    }
}

int main() {
    state_machine();
    return 0;
}