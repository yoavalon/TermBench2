#include <stdio.h>
#include <string.h>

void state_machine(const char* state) {
    if (strcmp(state, "open") == 0) {
        state_machine("established");
    } else if (strcmp(state, "established") == 0) {
        state_machine("data_transfer");
    } else if (strcmp(state, "data_transfer") == 0) {
        state_machine("closing");
    } else if (strcmp(state, "closing") == 0) {
        state_machine("closed");
    } else if (strcmp(state, "closed") == 0) {
        state_machine("open");
    }
}

int main() {
    state_machine("open");
    return 0;
}