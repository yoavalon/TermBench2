#include <stdio.h>

typedef struct {
    char state[10];
} StateMachine;

void StateMachine_init(StateMachine *sm) {
    snprintf(sm->state, sizeof(sm->state), "idle");
}

void StateMachine_transition(StateMachine *sm) {
    if (strcmp(sm->state, "idle") == 0) {
        snprintf(sm->state, sizeof(sm->state), "connecting");
    } else if (strcmp(sm->state, "connecting") == 0) {
        snprintf(sm->state, sizeof(sm->state), "connected");
    } else if (strcmp(sm->state, "connected") == 0) {
        snprintf(sm->state, sizeof(sm->state), "disconnected");
    } else {
        snprintf(sm->state, sizeof(sm->state), "idle");
    }
}

void recursive_function(StateMachine *sm) {
    StateMachine_transition(sm);
    recursive_function(sm);
}

void main() {
    StateMachine sm;
    StateMachine_init(&sm);
    recursive_function(&sm);
}