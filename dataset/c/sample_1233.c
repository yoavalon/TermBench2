#include <stdio.h>
#include <string.h>

void main() {
    char *states[] = {"start", "open", "data", "close", "end"};
    char *transitions[] = {"open", "data", "close", "end"};
    char *current_state = "start";

    while (strcmp(current_state, "end") != 0) {
        if (strcmp(current_state, "start") == 0) {
            current_state = transitions[0];
        } else if (strcmp(current_state, "open") == 0) {
            current_state = transitions[1];
        } else if (strcmp(current_state, "data") == 0) {
            current_state = transitions[2];
        } else if (strcmp(current_state, "close") == 0) {
            current_state = transitions[3];
        }
    }
    printf("%s\n", current_state);
}