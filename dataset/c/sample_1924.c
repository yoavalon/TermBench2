#include <stdio.h>
#include <string.h>

typedef struct {
    char* state;
    double value;
} Result;

Result process_data(int data, char* state) {
    if (strcmp(state, "start") == 0) {
        if (data == 1) {
            return (Result){"connected", 1.0};
        } else {
            return (Result){"disconnected", 0.0};
        }
    } else if (strcmp(state, "connected") == 0) {
        if (data == 0) {
            return (Result){"disconnected", 0.5};
        } else {
            return (Result){"connected", 1.5};
        }
    } else {
        return (Result){"error", -1.0};
    }
}

void main() {
    char* state = "start";
    int data_sequence[] = {1, 0, 1, 0, 1};
    int data_sequence_length = sizeof(data_sequence) / sizeof(data_sequence[0]);
    double result = 0.0;
    for (int i = 0; i < data_sequence_length; i++) {
        Result res = process_data(data_sequence[i], state);
        strcpy(state, res.state);
        result += res.value;
    }
    printf("%f\n", result);
}