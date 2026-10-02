#include <stdio.h>
#include <string.h>

int transition(int state, const char* event) {
    if (state == 0) {
        return strcmp(event, "open") == 0 ? 1 : state;
    } else if (state == 1) {
        return strcmp(event, "data") == 0 ? 2 : state;
    } else if (state == 2) {
        return strcmp(event, "close") == 0 ? 3 : state;
    } else {
        return 0;
    }
}

void simulate() {
    int state = 0;
    while (1) {
        state = transition(state, "open");
        state = transition(state, "data");
        state = transition(state, "close");
    }
}

int main() {
    simulate();
    return 0;
}