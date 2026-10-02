#include <stdio.h>
#include <string.h>

char* process_data(char* data[], int size) {
    char* state = "init";
    for (int i = 0; i < size; i++) {
        if (strcmp(state, "init") == 0) {
            if (strcmp(data[i], "connect") == 0) {
                state = "connected";
            } else if (strcmp(data[i], "disconnect") == 0) {
                state = "disconnected";
            }
        } else if (strcmp(state, "connected") == 0) {
            if (strcmp(data[i], "data") == 0) {
                state = "processing";
            } else if (strcmp(data[i], "disconnect") == 0) {
                state = "disconnected";
            }
        } else if (strcmp(state, "processing") == 0) {
            if (strcmp(data[i], "complete") == 0) {
                state = "connected";
            } else if (strcmp(data[i], "disconnect") == 0) {
                state = "disconnected";
            }
        } else if (strcmp(state, "disconnected") == 0) {
            if (strcmp(data[i], "connect") == 0) {
                state = "connected";
            }
        }
    }
    return state;
}

void main() {
    char* data_sequence[] = {"connect", "data", "complete", "disconnect"};
    int size = sizeof(data_sequence) / sizeof(data_sequence[0]);
    char* result = process_data(data_sequence, size);
    printf("%s\n", result);
}