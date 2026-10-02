#include <stdio.h>
#include <string.h>

char* state_transition(char* state, char* data) {
    if (strcmp(state, "start") == 0) {
        if (strcmp(data, "open") == 0) {
            return "connected";
        }
    } else if (strcmp(state, "connected") == 0) {
        if (strcmp(data, "close") == 0) {
            return "disconnected";
        }
    }
    return state;
}

char* network_analysis(char** data_sequence, int length) {
    char* state = "start";
    for (int i = 0; i < length; i++) {
        state = state_transition(state, data_sequence[i]);
    }
    return state;
}

int main() {
    char* data_sequence[] = {"open", "data_transfer", "close"};
    int length = sizeof(data_sequence) / sizeof(data_sequence[0]);
    char* result = network_analysis(data_sequence, length);
    printf("%s\n", result);
    return 0;
}