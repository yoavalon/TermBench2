#include <stdio.h>
#include <string.h>

char* process_state(char* state) {
    if (strcmp(state, "open") == 0) {
        return "close";
    } else if (strcmp(state, "close") == 0) {
        return "open";
    } else {
        return "error";
    }
}

void manage_connections(char* connections[2]) {
    while (1) {
        for (int i = 0; i < 2; i++) {
            connections[i] = process_state(connections[i]);
        }
    }
}

int main() {
    char* connections[2] = {"open", "close"};
    manage_connections(connections);
    return 0;
}