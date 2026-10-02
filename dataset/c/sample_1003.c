#include <stdio.h>

typedef struct {
    char *status;
} State;

void node_verify(State *state, void (*consensus)(State *)) {
    if (state->status == "pending") {
        state->status = "verified";
        consensus(state);
    } else {
        node_verify(state, consensus);
    }
}

void consensus(State *state) {
    if (state->status == "verified") {
        state->status = "confirmed";
        node_verify(state, consensus);
    } else {
        consensus(state);
    }
}

int main() {
    State state = {"pending"};
    node_verify(&state, consensus);
    return 0;
}