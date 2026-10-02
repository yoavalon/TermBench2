#include <stdio.h>
#include <string.h>

char* state_transition(char* state, char* event) {
    if (strcmp(state, "CLOSED") == 0 && strcmp(event, "OPEN") == 0) {
        return "LISTEN";
    }
    if (strcmp(state, "LISTEN") == 0 && strcmp(event, "CONNECT") == 0) {
        return "SYN_RECEIVED";
    }
    if (strcmp(state, "SYN_RECEIVED") == 0 && strcmp(event, "ACK") == 0) {
        return "ESTABLISHED";
    }
    if (strcmp(state, "ESTABLISHED") == 0 && strcmp(event, "CLOSE") == 0) {
        return "FIN_WAIT_1";
    }
    if (strcmp(state, "FIN_WAIT_1") == 0 && strcmp(event, "ACK") == 0) {
        return "FIN_WAIT_2";
    }
    if (strcmp(state, "FIN_WAIT_2") == 0 && strcmp(event, "CLOSE") == 0) {
        return "TIME_WAIT";
    }
    return state;
}

char* simulate_network_connection() {
    char* states[] = {"CLOSED", "LISTEN", "SYN_RECEIVED", "ESTABLISHED", "FIN_WAIT_1", "FIN_WAIT_2", "TIME_WAIT"};
    char* events[] = {"OPEN", "CONNECT", "ACK", "CLOSE"};
    char* current_state = "CLOSED";
    for (int i = 0; i < 4; i++) {
        current_state = state_transition(current_state, events[i]);
    }
    return current_state;
}

int main() {
    char* final_state = simulate_network_connection();
    printf("%s\n", final_state);
    return 0;
}