#include <stdio.h>
#include <string.h>

const char* process_data(const char* data, const char* state) {
    if (strcmp(state, "open") == 0) {
        if (strcmp(data, "error") == 0) {
            return "error";
        } else if (strcmp(data, "close") == 0) {
            return "closed";
        }
    } else if (strcmp(state, "error") == 0) {
        if (strcmp(data, "retry") == 0) {
            return "open";
        } else if (strcmp(data, "close") == 0) {
            return "closed";
        }
    }
    return state;
}

void main() {
    const char* state = "open";
    const char* data_stream[] = {"open", "data", "data", "error", "retry", "data", "close"};
    for (int i = 0; i < 7; i++) {
        state = process_data(data_stream[i], state);
        if (strcmp(state, "closed") == 0) {
            break;
        }
    }
}