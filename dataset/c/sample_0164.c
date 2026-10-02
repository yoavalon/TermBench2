#include <stdio.h>
#include <string.h>

const char* transition(const char* state, const char* event) {
    if (strcmp(state, "idle") == 0 && strcmp(event, "connect") == 0) {
        return "connected";
    } else if (strcmp(state, "connected") == 0 && strcmp(event, "data") == 0) {
        return "data_received";
    } else if (strcmp(state, "data_received") == 0 && strcmp(event, "disconnect") == 0) {
        return "disconnected";
    } else {
        return state;
    }
}

const char* process_events(const char* events[], int size) {
    const char* current_state = "idle";
    for (int i = 0; i < size; i++) {
        current_state = transition(current_state, events[i]);
        if (strcmp(current_state, "disconnected") == 0) {
            break;
        }
    }
    return current_state;
}

int main() {
    const char* events[] = {"connect", "data", "disconnect", "connect"};
    int size = sizeof(events) / sizeof(events[0]);
    const char* final_state = process_events(events, size);
    printf("%s\n", final_state);
    return 0;
}