#include <stdio.h>
#include <string.h>

void process_state(char* state, char* data, char* next_state, char* next_data) {
    if (strcmp(state, "start") == 0) {
        strcpy(next_state, "connect");
        strcpy(next_data, data);
    } else if (strcmp(state, "connect") == 0) {
        if (strcmp(data, "success") == 0) {
            strcpy(next_state, "data_transfer");
            strcpy(next_data, data);
        } else {
            strcpy(next_state, "error");
            strcpy(next_data, data);
        }
    } else if (strcmp(state, "data_transfer") == 0) {
        if (strcmp(data, "complete") == 0) {
            strcpy(next_state, "disconnect");
            strcpy(next_data, data);
        } else {
            strcpy(next_state, "data_transfer");
            strcpy(next_data, data);
        }
    } else if (strcmp(state, "error") == 0) {
        strcpy(next_state, "disconnect");
        strcpy(next_data, data);
    } else if (strcmp(state, "disconnect") == 0) {
        strcpy(next_state, "end");
        strcpy(next_data, data);
    } else {
        strcpy(next_state, "end");
        strcpy(next_data, data);
    }
}

void run_network_protocol(char* data_sequence[], int sequence_length) {
    char current_state[20] = "start";
    char next_state[20];
    char next_data[20];
    for (int i = 0; i < sequence_length; i++) {
        process_state(current_state, data_sequence[i], next_state, next_data);
        strcpy(current_state, next_state);
        if (strcmp(current_state, "end") == 0) {
            break;
        }
    }
}

int main() {
    char* data_sequence[] = {"success", "complete"};
    int sequence_length = sizeof(data_sequence) / sizeof(data_sequence[0]);
    run_network_protocol(data_sequence, sequence_length);
    return 0;
}