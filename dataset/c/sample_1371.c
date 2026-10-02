#include <stdio.h>
#include <string.h>

const char* process_connection(const char* state, const char* event) {
    if (strcmp(state, "idle") == 0 && strcmp(event, "connect") == 0) {
        return "connected";
    } else if (strcmp(state, "connected") == 0 && strcmp(event, "data") == 0) {
        return "data_received";
    } else if (strcmp(state, "data_received") == 0 && strcmp(event, "disconnect") == 0) {
        return "disconnected";
    }
    return state;
}

void manage_state_machine() {
    const char* state = "idle";
    const char* events[] = {"connect", "data", "disconnect"};
    for (int i = 0; i < 3; i++) {
        state = process_connection(state, events[i]);
        if (strcmp(state, "disconnected") == 0) {
            break;
        }
    }
}

int main() {
    manage_state_machine();
    return 0;
}