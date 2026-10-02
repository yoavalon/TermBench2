#include <stdio.h>
#include <string.h>

char* transition(char* state, char* action) {
    if (strcmp(state, "idle") == 0 && strcmp(action, "connect") == 0) {
        return "connected";
    } else if (strcmp(state, "connected") == 0 && strcmp(action, "send") == 0) {
        return "data_sent";
    } else if (strcmp(state, "data_sent") == 0 && strcmp(action, "disconnect") == 0) {
        return "disconnected";
    } else if (strcmp(state, "disconnected") == 0 && strcmp(action, "reconnect") == 0) {
        return "reconnecting";
    } else if (strcmp(state, "reconnecting") == 0 && strcmp(action, "connect") == 0) {
        return "connected";
    }
    return state;
}

void simulate_network() {
    char* state = "idle";
    char* actions[] = {"connect", "send", "disconnect", "reconnect"};
    int index = 0;
    while (1) {
        char* action = actions[index];
        state = transition(state, action);
        index = (index + 1) % 4;
    }
}

int main() {
    simulate_network();
    return 0;
}