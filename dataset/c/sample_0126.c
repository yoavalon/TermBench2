#include <stdio.h>
#include <string.h>

char* process_connection(char* state, char* data) {
    if (strcmp(state, "init") == 0) {
        if (strcmp(data, "connect") == 0) {
            return "connected";
        }
    } else if (strcmp(state, "connected") == 0) {
        if (strcmp(data, "data") == 0) {
            return "processing";
        } else if (strcmp(data, "disconnect") == 0) {
            return "disconnected";
        }
    } else if (strcmp(state, "processing") == 0) {
        if (strcmp(data, "complete") == 0) {
            return "connected";
        } else if (strcmp(data, "disconnect") == 0) {
            return "disconnected";
        }
    } else if (strcmp(state, "disconnected") == 0) {
        if (strcmp(data, "connect") == 0) {
            return "connected";
        }
    }
    return state;
}

void main() {
    char* states[] = {"init", "connected", "processing", "disconnected"};
    char* data_sequence[] = {"connect", "data", "complete", "disconnect", "connect"};
    char* current_state = "init";
    for (int i = 0; i < 5; i++) {
        current_state = process_connection(current_state, data_sequence[i]);
        int valid_state = 0;
        for (int j = 0; j < 4; j++) {
            if (strcmp(current_state, states[j]) == 0) {
                valid_state = 1;
                break;
            }
        }
        if (!valid_state) {
            break;
        }
    }
}