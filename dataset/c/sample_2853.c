#include <stdio.h>
#include <string.h>

const char* transition(const char* state, const char* event) {
    if (strcmp(state, "init") == 0 && strcmp(event, "connect") == 0) {
        return "connected";
    } else if (strcmp(state, "connected") == 0 && strcmp(event, "data") == 0) {
        return "transmitting";
    } else if (strcmp(state, "transmitting") == 0 && strcmp(event, "disconnect") == 0) {
        return "disconnected";
    } else {
        return state;
    }
}

void sequence() {
    const char* state = "init";
    const char* events[] = {"connect", "data", "disconnect", "connect", "data", "disconnect"};
    while (1) {
        for (int i = 0; i < 6; i++) {
            state = transition(state, events[i]);
            printf("%s\n", state);
        }
    }
}

int main() {
    sequence();
    return 0;
}