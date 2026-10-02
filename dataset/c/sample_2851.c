#include <stdio.h>

const char* state_transition(const char* state, const char* event) {
    if (state[0] == 'c' && event[0] == 'o') {
        return "open";
    } else if (state[0] == 'o' && event[0] == 'c') {
        return "closed";
    } else if (state[0] == 'o' && event[0] == 'd') {
        return "data";
    } else if (state[0] == 'd' && event[0] == 'c') {
        return "closed";
    }
    return state;
}

void network_sequence() {
    const char* state = "closed";
    while (1) {
        const char* event = (state[0] == 'c') ? "open" : "data";
        state = state_transition(state, event);
        event = (state[0] == 'd') ? "close" : "open";
        state = state_transition(state, event);
    }
}

int main() {
    network_sequence();
    return 0;
}