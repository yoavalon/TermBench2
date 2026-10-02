#include <stdio.h>
#include <string.h>

char* transition(char* state, char* event) {
    if (strcmp(state, "CLOSED") == 0 && strcmp(event, "OPEN") == 0) {
        return "OPEN";
    } else if (strcmp(state, "OPEN") == 0 && strcmp(event, "DATA") == 0) {
        return "DATA";
    } else if (strcmp(state, "DATA") == 0 && strcmp(event, "CLOSE") == 0) {
        return "CLOSED";
    } else if (strcmp(state, "CLOSED") == 0 && strcmp(event, "ERROR") == 0) {
        return "ERROR";
    }
    return state;
}

char* simulate() {
    char* state = "CLOSED";
    char* events[] = {"OPEN", "DATA", "CLOSE", "ERROR", "DATA", "CLOSE"};
    for (int i = 0; i < 6; i++) {
        state = transition(state, events[i]);
    }
    return state;
}

int main() {
    char* final_state = simulate();
    printf("%s\n", final_state);
    return 0;
}