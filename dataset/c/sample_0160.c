#include <stdio.h>
#include <string.h>

const char* state_machine(const char* state, const char* event) {
    if (strcmp(state, "start") == 0 && strcmp(event, "connect") == 0)
        return "connected";
    else if (strcmp(state, "connected") == 0 && strcmp(event, "disconnect") == 0)
        return "disconnected";
    else if (strcmp(state, "disconnected") == 0 && strcmp(event, "connect") == 0)
        return "connected";
    else if (strcmp(state, "connected") == 0 && strcmp(event, "data") == 0)
        return "processing";
    else if (strcmp(state, "processing") == 0 && strcmp(event, "complete") == 0)
        return "connected";
    else if (strcmp(state, "connected") == 0 && strcmp(event, "error") == 0)
        return "error";
    else if (strcmp(state, "error") == 0 && strcmp(event, "recover") == 0)
        return "connected";
    return state;
}

void process_events() {
    const char* states[] = {"start", "connected", "disconnected", "processing", "error"};
    const char* events[] = {"connect", "disconnect", "data", "complete", "error", "recover"};
    const char* current_state = "start";
    for (int i = 0; i < 6; i++) {
        current_state = state_machine(current_state, events[i]);
        if (strcmp(current_state, "error") == 0)
            break;
    }
}

int main() {
    process_events();
    return 0;
}