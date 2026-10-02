#include <stdio.h>
#include <string.h>

typedef struct State State;
typedef struct OpenState OpenState;
typedef struct ClosedState ClosedState;
typedef struct ErrorState ErrorState;

struct State {
    const char* name;
    State* (*transition)(State*, const char*, State*);
};

struct OpenState {
    State base;
};

struct ClosedState {
    State base;
};

struct ErrorState {
    State base;
};

State* OpenState_transition(State* self, const char* event, State* states[]) {
    if (strcmp(event, "close") == 0) {
        return states[1]; // closed
    } else if (strcmp(event, "error") == 0) {
        return states[2]; // error
    }
    return self;
}

State* ClosedState_transition(State* self, const char* event, State* states[]) {
    if (strcmp(event, "open") == 0) {
        return states[0]; // open
    }
    return self;
}

State* ErrorState_transition(State* self, const char* event, State* states[]) {
    if (strcmp(event, "recover") == 0) {
        return states[0]; // open
    }
    return self;
}

State* process_events(State* current_state, const char* events[], int event_count, State* states[]) {
    if (event_count == 0) {
        return current_state;
    }
    State* next_state = current_state->transition(current_state, events[0], states);
    return process_events(next_state, events + 1, event_count - 1, states);
}

int main() {
    OpenState open_state = {{ "open", OpenState_transition }};
    ClosedState closed_state = {{ "closed", ClosedState_transition }};
    ErrorState error_state = {{ "error", ErrorState_transition }};
    State* states[] = { (State*)&open_state, (State*)&closed_state, (State*)&error_state };
    State* current_state = states[1]; // closed
    const char* event_sequence[] = { "open", "data", "data", "close", "open", "error", "recover", "close" };
    State* final_state = process_events(current_state, event_sequence, 8, states);
    printf("%s\n", final_state->name);
    return 0;
}