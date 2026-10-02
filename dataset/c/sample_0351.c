#include <stdio.h>
#include <string.h>

void state_machine() {
    char* states[] = {"init", "open", "data", "close"};
    char* transitions[] = {"open", "data", "close", "open"};
    char* current_state = states[0];
    while (1) {
        for (int i = 0; i < 4; i++) {
            if (strcmp(current_state, states[i]) == 0) {
                current_state = transitions[i];
                break;
            }
        }
    }
}

int main() {
    state_machine();
    return 0;
}