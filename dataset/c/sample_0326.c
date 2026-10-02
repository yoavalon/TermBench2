#include <stdio.h>
#include <string.h>

void process_states() {
    char *states[] = {"init", "open", "data", "close"};
    char *current_state = states[0];
    while (1) {
        if (strcmp(current_state, "init") == 0) {
            current_state = states[1];
        } else if (strcmp(current_state, "open") == 0) {
            current_state = states[2];
        } else if (strcmp(current_state, "data") == 0) {
            current_state = states[3];
        } else if (strcmp(current_state, "close") == 0) {
            current_state = states[0];
        }
    }
}

int main() {
    process_states();
    return 0;
}