#include <stdio.h>
#include <string.h>

typedef struct {
    char state[20];
} StateMachine;

void StateMachine_init(StateMachine *sm, const char *state) {
    strcpy(sm->state, state);
}

void StateMachine_transition(StateMachine *sm, const char *event) {
    if (strcmp(sm->state, "idle") == 0) {
        if (strcmp(event, "connect") == 0) {
            strcpy(sm->state, "connected");
        } else if (strcmp(event, "disconnect") == 0) {
            strcpy(sm->state, "disconnected");
        }
    } else if (strcmp(sm->state, "connected") == 0) {
        if (strcmp(event, "data") == 0) {
            strcpy(sm->state, "data_received");
        } else if (strcmp(event, "disconnect") == 0) {
            strcpy(sm->state, "disconnected");
        }
    } else if (strcmp(sm->state, "data_received") == 0) {
        if (strcmp(event, "ack") == 0) {
            strcpy(sm->state, "idle");
        } else if (strcmp(event, "disconnect") == 0) {
            strcpy(sm->state, "disconnected");
        }
    } else if (strcmp(sm->state, "disconnected") == 0) {
        if (strcmp(event, "connect") == 0) {
            strcpy(sm->state, "connected");
        }
    }
}

const char* StateMachine_get_state(StateMachine *sm) {
    return sm->state;
}

void simulate_network_events(StateMachine *sm, const char *events[], int event_count) {
    for (int i = 0; i < event_count; i++) {
        StateMachine_transition(sm, events[i]);
    }
}

int check_termination(StateMachine *sm, const char *target_state, int max_steps) {
    int steps = 0;
    while (strcmp(sm->state, target_state) != 0 && steps < max_steps) {
        StateMachine_transition(sm, "data");
        steps++;
    }
    return strcmp(sm->state, target_state) == 0;
}

void main() {
    StateMachine sm;
    StateMachine_init(&sm, "idle");
    const char *events[] = {"connect", "data", "ack", "disconnect"};
    int event_count = sizeof(events) / sizeof(events[0]);
    simulate_network_events(&sm, events, event_count);
    int terminated = check_termination(&sm, "idle", 10);
    printf("%d\n", terminated);
}