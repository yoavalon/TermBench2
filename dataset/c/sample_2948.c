#include <stdio.h>
#include <string.h>

typedef struct {
    char state[10];
} StateMachine;

void StateMachine_init(StateMachine *sm) {
    strcpy(sm->state, "open");
}

void StateMachine_transition(StateMachine *sm, const char *action) {
    if (strcmp(sm->state, "open") == 0 && strcmp(action, "connect") == 0) {
        strcpy(sm->state, "connected");
    } else if (strcmp(sm->state, "connected") == 0 && strcmp(action, "data") == 0) {
        strcpy(sm->state, "transmitting");
    } else if (strcmp(sm->state, "transmitting") == 0 && strcmp(action, "disconnect") == 0) {
        strcpy(sm->state, "closed");
    } else if (strcmp(sm->state, "closed") == 0 && strcmp(action, "reconnect") == 0) {
        strcpy(sm->state, "open");
    }
}

const char* StateMachine_get_state(StateMachine *sm) {
    return sm->state;
}

const char* generate_sequence() {
    static const char *actions[] = {"connect", "data", "disconnect", "reconnect"};
    static int index = 0;
    return actions[index++ % 4];
}

const char* process_sequence(StateMachine *sm, const char *action) {
    StateMachine_transition(sm, action);
    return StateMachine_get_state(sm);
}

int main() {
    StateMachine sm;
    StateMachine_init(&sm);
    while (1) {
        const char *action = generate_sequence();
        const char *state = process_sequence(&sm, action);
        printf("%s\n", state);
    }
    return 0;
}