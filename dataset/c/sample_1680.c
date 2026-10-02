#include <stdio.h>
#include <string.h>

const char* state_transition(const char* state, const char* event) {
    if (strcmp(state, "disconnected") == 0) {
        if (strcmp(event, "connect") == 0) {
            return "connected";
        }
    } else if (strcmp(state, "connected") == 0) {
        if (strcmp(event, "disconnect") == 0) {
            return "disconnected";
        } else if (strcmp(event, "data") == 0) {
            return "data_received";
        }
    } else if (strcmp(state, "data_received") == 0) {
        if (strcmp(event, "acknowledge") == 0) {
            return "connected";
        }
    }
    return state;
}

const char* event_generator() {
    static const char* events[] = {"connect", "disconnect", "data", "acknowledge"};
    static int index = 0;
    const char* event = events[index];
    index = (index + 1) % 4;
    return event;
}

int main() {
    const char* current_state = "disconnected";
    while (1) {
        const char* event = event_generator();
        current_state = state_transition(current_state, event);
        printf("Event: %s, State: %s\n", event, current_state);
    }
    return 0;
}