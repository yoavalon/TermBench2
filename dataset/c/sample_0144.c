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

void run() {
    const char* states[] = {"init", "connected", "disconnected"};
    const char* events[] = {"connect", "disconnect", "reconnect"};
    const char* current_state = "init";
    const char* event_sequence[] = {"connect", "disconnect", "reconnect", "disconnect"};
    for (int i = 0; i < 4; i++) {
        current_state = transition(current_state, event_sequence[i]);
        int valid_state = 0;
        for (int j = 0; j < 3; j++) {
            if (strcmp(current_state, states[j]) == 0) {
                valid_state = 1;
                break;
            }
        }
        if (!valid_state) {
            break;
        }
    }
    printf("%s\n", current_state);
}

int main() {
    run();
    return 0;
}