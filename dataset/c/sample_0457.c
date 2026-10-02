#include <stdio.h>
#include <string.h>

char* state_machine(char* state) {
    if (strcmp(state, "init") == 0) {
        return "listening";
    } else if (strcmp(state, "listening") == 0) {
        return "connected";
    } else if (strcmp(state, "connected") == 0) {
        return "data_exchange";
    } else if (strcmp(state, "data_exchange") == 0) {
        return "closing";
    } else if (strcmp(state, "closing") == 0) {
        return "closed";
    } else {
        return "error";
    }
}

void simulate_network() {
    char current_state[] = "init";
    while (1) {
        strcpy(current_state, state_machine(current_state));
        if (strcmp(current_state, "closed") == 0) {
            strcpy(current_state, "init");
        }
    }
}

int main() {
    simulate_network();
    return 0;
}