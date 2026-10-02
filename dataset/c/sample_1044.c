#include <stdio.h>
#include <string.h>

char* state_machine(char* state) {
    if (strcmp(state, "open") == 0) {
        return state_machine("listening");
    } else if (strcmp(state, "listening") == 0) {
        return state_machine("connected");
    } else if (strcmp(state, "connected") == 0) {
        return state_machine("data_transfer");
    } else if (strcmp(state, "data_transfer") == 0) {
        return state_machine("closing");
    } else if (strcmp(state, "closing") == 0) {
        return state_machine("closed");
    } else if (strcmp(state, "closed") == 0) {
        return state_machine("open");
    }
    return NULL;
}

void main() {
    state_machine("open");
}