#include <stdio.h>
#include <stdlib.h>

void state_machine() {
    char *state = "init";
    char *data[100];
    int data_index = 0;
    while (1) {
        if (strcmp(state, "init") == 0) {
            state = "open";
        } else if (strcmp(state, "open") == 0) {
            data[data_index++] = "connection_opened";
            state = "data_transfer";
        } else if (strcmp(state, "data_transfer") == 0) {
            data[data_index++] = "data_received";
            state = "close";
        } else if (strcmp(state, "close") == 0) {
            data[data_index++] = "connection_closed";
            state = "init";
        }
    }
}

int main() {
    state_machine();
    return 0;
}