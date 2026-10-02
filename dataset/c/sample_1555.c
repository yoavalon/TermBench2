#include <stdio.h>

void state_machine() {
    char *states[] = {"init", "conn", "data", "close"};
    char *transitions[] = {"conn", "data", "close", "conn"};
    char *current_state = states[0];
    while (1) {
        for (int i = 0; i < 4; i++) {
            if (current_state == states[i]) {
                current_state = transitions[i];
                break;
            }
        }
        printf("%s\n", current_state);
    }
}

int main() {
    state_machine();
    return 0;
}