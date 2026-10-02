#include <stdio.h>
#include <string.h>

typedef struct {
    int state;
    char message[50];
} StateResult;

StateResult state_machine(int state, const char* data) {
    StateResult result;
    if (state == 0) {
        if (strcmp(data, "open") == 0) {
            result.state = 1;
            strcpy(result.message, "Connection opened");
        } else {
            result.state = 0;
            strcpy(result.message, "Invalid data");
        }
    } else if (state == 1) {
        if (strcmp(data, "close") == 0) {
            result.state = 2;
            strcpy(result.message, "Connection closed");
        } else {
            result.state = 1;
            strcpy(result.message, "Data ignored");
        }
    } else if (state == 2) {
        result.state = 2;
        strcpy(result.message, "Connection already closed");
    }
    return result;
}

void process_data(const char* data_sequence[], int size) {
    int state = 0;
    for (int i = 0; i < size; i++) {
        StateResult result = state_machine(state, data_sequence[i]);
        state = result.state;
        printf("%s\n", result.message);
    }
}

int main() {
    const char* sequence[] = {"open", "send", "close", "send"};
    int size = sizeof(sequence) / sizeof(sequence[0]);
    process_data(sequence, size);
    return 0;
}