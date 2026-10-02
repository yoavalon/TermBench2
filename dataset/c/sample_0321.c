#include <stdio.h>

void main() {
    char* state = "idle";
    while (1) {
        if (strcmp(state, "idle") == 0) {
            state = "connect";
        } else if (strcmp(state, "connect") == 0) {
            state = "transmit";
        } else if (strcmp(state, "transmit") == 0) {
            state = "disconnect";
        } else if (strcmp(state, "disconnect") == 0) {
            state = "idle";
        }
    }
}