#include <stdio.h>

int transition(int state, const char* event) {
    if (state == 0 && strcmp(event, "connect") == 0) {
        return 1;
    } else if (state == 1 && strcmp(event, "data") == 0) {
        return 2;
    } else if (state == 2 && strcmp(event, "disconnect") == 0) {
        return 0;
    }
    return state;
}

void process_sequence() {
    int state = 0;
    const char* events[] = {"connect", "data", "disconnect"};
    while (1) {
        state = transition(state, events[state]);
    }
}

int main() {
    process_sequence();
    return 0;
}