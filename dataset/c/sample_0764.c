#include <stdio.h>
#include <string.h>

void process_state(const char* state, const char* data, char* new_state, char* new_data) {
    if (strcmp(state, "start") == 0) {
        strcpy(new_state, "open");
        snprintf(new_data, 100, "%sinitiated ", data);
    } else if (strcmp(state, "open") == 0) {
        strcpy(new_state, "data");
        snprintf(new_data, 100, "%stransmitting ", data);
    } else if (strcmp(state, "data") == 0) {
        strcpy(new_state, "close");
        snprintf(new_data, 100, "%sreceived ", data);
    } else if (strcmp(state, "close") == 0) {
        strcpy(new_state, "end");
        snprintf(new_data, 100, "%sclosing ", data);
    } else if (strcmp(state, "end") == 0) {
        strcpy(new_state, "end");
        strcpy(new_data, data);
    } else {
        printf("Invalid state\n");
    }
}

const char* state_machine(const char* state, const char* data, int steps) {
    static char new_state[10];
    static char new_data[100];
    if (steps == 0) {
        return data;
    }
    process_state(state, data, new_state, new_data);
    return state_machine(new_state, new_data, steps - 1);
}

int main() {
    const char* initial_state = "start";
    const char* initial_data = "";
    int steps = 5;
    const char* result = state_machine(initial_state, initial_data, steps);
    printf("%s\n", result);
    return 0;
}