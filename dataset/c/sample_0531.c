#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct State State;
typedef struct ClosedState ClosedState;
typedef struct OpenState OpenState;
typedef struct DataState DataState;

struct State {
    State* (*transition)(State* self, const char* event);
};

struct ClosedState {
    State state;
};

struct OpenState {
    State state;
};

struct DataState {
    State state;
};

State* ClosedState_transition(State* self, const char* event) {
    if (strcmp(event, "open") == 0) {
        OpenState* new_state = (OpenState*)malloc(sizeof(OpenState));
        new_state->state.transition = OpenState_transition;
        return (State*)new_state;
    }
    return self;
}

State* OpenState_transition(State* self, const char* event) {
    if (strcmp(event, "close") == 0) {
        ClosedState* new_state = (ClosedState*)malloc(sizeof(ClosedState));
        new_state->state.transition = ClosedState_transition;
        return (State*)new_state;
    }
    if (strcmp(event, "data") == 0) {
        DataState* new_state = (DataState*)malloc(sizeof(DataState));
        new_state->state.transition = DataState_transition;
        return (State*)new_state;
    }
    return self;
}

State* DataState_transition(State* self, const char* event) {
    if (strcmp(event, "close") == 0) {
        ClosedState* new_state = (ClosedState*)malloc(sizeof(ClosedState));
        new_state->state.transition = ClosedState_transition;
        return (State*)new_state;
    }
    if (strcmp(event, "data") == 0) {
        return self;
    }
    OpenState* new_state = (OpenState*)malloc(sizeof(OpenState));
    new_state->state.transition = OpenState_transition;
    return (State*)new_state;
}

const char* event_generator() {
    static const char* states[] = {"open", "data", "close"};
    static int index = 0;
    const char* current_event = states[index];
    index = (index + 1) % 3;
    return current_event;
}

void state_machine() {
    ClosedState initial_state;
    initial_state.state.transition = ClosedState_transition;
    State* current_state = (State*)&initial_state;

    while (1) {
        const char* event = event_generator();
        current_state = current_state->transition(current_state, event);
    }
}

int main() {
    state_machine();
    return 0;
}