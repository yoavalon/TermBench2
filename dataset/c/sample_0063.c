#include <stdio.h>
#include <string.h>

char* state_machine() {
    char* states[] = {"DISCONNECTED", "CONNECTING", "CONNECTED", "TERMINATING"};
    char* current_state = states[0];
    for (int i = 0; i < 3; i++) {
        if (strcmp(current_state, "CONNECTED") == 0) {
            current_state = states[3];
            break;
        }
        current_state = states[i + 1];
    }
    return current_state;
}

int main() {
    printf("%s\n", state_machine());
    return 0;
}