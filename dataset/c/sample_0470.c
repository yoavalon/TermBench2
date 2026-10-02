#include <stdio.h>
#include <string.h>

char* state_machine(char* state) {
    if (strcmp(state, "open") == 0) {
        return "wait";
    } else if (strcmp(state, "wait") == 0) {
        return "close";
    } else if (strcmp(state, "close") == 0) {
        return "open";
    } else {
        return "error";
    }
}

void process_network() {
    char* current_state = "open";
    while (1) {
        current_state = state_machine(current_state);
    }
}

int main() {
    process_network();
    return 0;
}