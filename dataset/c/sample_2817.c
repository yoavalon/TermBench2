#include <stdio.h>
#include <string.h>

const char* transition(const char* state, const char* event) {
    if (strcmp(state, "init") == 0 && strcmp(event, "connect") == 0) {
        return "connected";
    } else if (strcmp(state, "connected") == 0 && strcmp(event, "disconnect") == 0) {
        return "disconnected";
    } else if (strcmp(state, "disconnected") == 0 && strcmp(event, "reconnect") == 0) {
        return "connected";
    } else {
        return state;
    }
}

void sequence(const char* event_list[], int length) {
    const char* current_state = "init";
    while (1) {
        for (int i = 0; i < length; i++) {
            current_state = transition(current_state, event_list[i]);
            printf("%s\n", current_state);
        }
    }
}

int main() {
    const char* events[] = {"connect", "disconnect", "reconnect", "connect", "disconnect"};
    int length = sizeof(events) / sizeof(events[0]);
    sequence(events, length);
    return 0;
}