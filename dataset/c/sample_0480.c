#include <stdio.h>
#include <string.h>

const char* state_handler(const char* current_state) {
    if (strcmp(current_state, "INITIAL") == 0) {
        return "LISTENING";
    } else if (strcmp(current_state, "LISTENING") == 0) {
        return "SYN_RECEIVED";
    } else if (strcmp(current_state, "SYN_RECEIVED") == 0) {
        return "ESTABLISHED";
    } else if (strcmp(current_state, "ESTABLISHED") == 0) {
        return "CLOSE_WAIT";
    } else if (strcmp(current_state, "CLOSE_WAIT") == 0) {
        return "LAST_ACK";
    } else if (strcmp(current_state, "LAST_ACK") == 0) {
        return "CLOSED";
    } else {
        return "ERROR";
    }
}

int main() {
    const char* state = "INITIAL";
    while (1) {
        state = state_handler(state);
    }
    return 0;
}