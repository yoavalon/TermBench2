#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key1;
    char* key2;
    char* value;
} Transition;

typedef struct {
    Transition* transitions;
    int size;
} TransitionTable;

char* state_machine(char* initial_state, TransitionTable* transitions, char** input_sequence, int sequence_length) {
    char* current_state = initial_state;
    for (int i = 0; i < sequence_length; i++) {
        int found = 0;
        for (int j = 0; j < transitions->size; j++) {
            if (strcmp(transitions->transitions[j].key1, current_state) == 0 && strcmp(transitions->transitions[j].key2, input_sequence[i]) == 0) {
                current_state = transitions->transitions[j].value;
                found = 1;
                break;
            }
        }
        if (!found) {
            fprintf(stderr, "Invalid state transition\n");
            exit(EXIT_FAILURE);
        }
    }
    return current_state;
}

void process_network_data(char** data, int data_length) {
    char* initial = "idle";
    Transition transitions[] = {
        {"idle", "open", "connected"},
        {"connected", "data", "data_transfer"},
        {"data_transfer", "close", "closing"},
        {"closing", "ack", "closed"}
    };
    TransitionTable transition_table = {transitions, 4};
    char* final_state = state_machine(initial, &transition_table, data, data_length);
    if (strcmp(final_state, "closed") != 0) {
        fprintf(stderr, "Network connection did not terminate properly\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char* sequence[] = {"open", "data", "close", "ack"};
    int sequence_length = 4;
    process_network_data(sequence, sequence_length);
    return 0;
}