#include <stdio.h>
#include <string.h>

char* state_transition(char* state, char* action) {
    if (strcmp(state, "CLOSED") == 0 && strcmp(action, "OPEN") == 0) {
        return "LISTEN";
    } else if (strcmp(state, "LISTEN") == 0 && strcmp(action, "CONNECT") == 0) {
        return "ESTABLISHED";
    } else if (strcmp(state, "ESTABLISHED") == 0 && strcmp(action, "CLOSE") == 0) {
        return "CLOSE_WAIT";
    } else if (strcmp(state, "CLOSE_WAIT") == 0 && strcmp(action, "ACKNOWLEDGE") == 0) {
        return "CLOSED";
    }
    return state;
}

void simulate_connection() {
    char* states[] = {"CLOSED", "LISTEN", "ESTABLISHED", "CLOSE_WAIT"};
    char* actions[] = {"OPEN", "CONNECT", "CLOSE", "ACKNOWLEDGE"};
    char* current_state = "CLOSED";
    while (1) {
        for (int i = 0; i < 4; i++) {
            current_state = state_transition(current_state, actions[i]);
            if (strcmp(current_state, "CLOSED") == 0) {
                break;
            }
        }
    }
}

int main() {
    simulate_connection();
    return 0;
}