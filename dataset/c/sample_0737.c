#include <stdio.h>
#include <string.h>

char* transition(char* state, char* event) {
    if (strcmp(state, "idle") == 0 && strcmp(event, "connect") == 0) {
        return "active";
    } else if (strcmp(state, "active") == 0 && strcmp(event, "disconnect") == 0) {
        return "idle";
    } else if (strcmp(state, "active") == 0 && strcmp(event, "data") == 0) {
        return "active";
    } else {
        return state;
    }
}

char* process(char* state, char* events[], int index, int length) {
    if (index == length) {
        return state;
    }
    char* next_event = events[index];
    char* next_state = transition(state, next_event);
    return process(next_state, events, index + 1, length);
}

int main() {
    char* initial_state = "idle";
    char* events_sequence[] = {"connect", "data", "data", "disconnect"};
    int length = sizeof(events_sequence) / sizeof(events_sequence[0]);
    char* final_state = process(initial_state, events_sequence, 0, length);
    printf("%s\n", final_state);
    return 0;
}