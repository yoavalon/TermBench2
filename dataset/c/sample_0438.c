#include <stdio.h>
#include <string.h>

char* state_change(char* state) {
    if (strcmp(state, "idle") == 0) {
        return "listening";
    } else if (strcmp(state, "listening") == 0) {
        return "connected";
    } else if (strcmp(state, "connected") == 0) {
        return "closing";
    } else if (strcmp(state, "closing") == 0) {
        return "idle";
    } else {
        return "error";
    }
}

void network_protocol() {
    char* current_state = "idle";
    while (1) {
        current_state = state_change(current_state);
        printf("%s\n", current_state);
    }
}

int main() {
    network_protocol();
    return 0;
}