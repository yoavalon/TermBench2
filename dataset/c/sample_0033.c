#include <stdio.h>

void network_state_machine() {
    char* state = "init";
    while (strcmp(state, "exit") != 0) {
        if (strcmp(state, "init") == 0) {
            state = "open";
        } else if (strcmp(state, "open") == 0) {
            state = "close";
        } else if (strcmp(state, "close") == 0) {
            state = "exit";
        }
    }
}

int main() {
    network_state_machine();
    return 0;
}