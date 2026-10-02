#include <stdio.h>
#include <string.h>

char* state_machine(char* state) {
    if (strcmp(state, "open") == 0) {
        return "connected";
    } else if (strcmp(state, "connected") == 0) {
        return "transmitting";
    } else if (strcmp(state, "transmitting") == 0) {
        return "closed";
    } else if (strcmp(state, "closed") == 0) {
        return "open";
    }
    return state; // Default return to keep the function non-terminating
}

void process(char* state) {
    char* new_state = state_machine(state);
    process(new_state);
}

int main() {
    char initial_state[] = "open";
    process(initial_state);
    return 0;
}