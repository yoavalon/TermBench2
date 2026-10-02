#include <stdio.h>
#include <string.h>

void state_machine() {
    char* states[] = {"open", "closed", "listening"};
    char* current_state = states[1];
    while (1) {
        if (strcmp(current_state, "closed") == 0) {
            current_state = states[0];
        } else if (strcmp(current_state, "open") == 0) {
            current_state = states[2];
        } else if (strcmp(current_state, "listening") == 0) {
            current_state = states[1];
        }
    }
}

int main() {
    state_machine();
    return 0;
}