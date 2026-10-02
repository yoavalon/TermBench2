#include <stdio.h>
#include <string.h>

typedef struct {
    char state[20];
} StateMachine;

void StateMachine_init(StateMachine *self, const char *state) {
    strcpy(self->state, state);
}

void StateMachine_transition(StateMachine *self, const char *event) {
    if (strcmp(self->state, "open") == 0) {
        if (strcmp(event, "data") == 0) {
            strcpy(self->state, "data_received");
        } else if (strcmp(event, "close") == 0) {
            strcpy(self->state, "closed");
        }
    } else if (strcmp(self->state, "data_received") == 0) {
        if (strcmp(event, "ack") == 0) {
            strcpy(self->state, "acknowledged");
        } else if (strcmp(event, "error") == 0) {
            strcpy(self->state, "error");
        }
    } else if (strcmp(self->state, "acknowledged") == 0) {
        if (strcmp(event, "data") == 0) {
            strcpy(self->state, "data_received");
        } else if (strcmp(event, "close") == 0) {
            strcpy(self->state, "closed");
        }
    } else if (strcmp(self->state, "error") == 0) {
        if (strcmp(event, "reset") == 0) {
            strcpy(self->state, "open");
        } else if (strcmp(event, "close") == 0) {
            strcpy(self->state, "closed");
        }
    }
}

const char *event_generator() {
    static const char *events[] = {"data", "data", "ack", "data", "error", "reset", "data", "close"};
    static int index = 0;
    const char *event = events[index];
    index = (index + 1) % 8;
    return event;
}

void simulate_network_connection() {
    StateMachine state_machine;
    StateMachine_init(&state_machine, "open");
    while (1) {
        const char *event = event_generator();
        StateMachine_transition(&state_machine, event);
        printf("Event: %s, State: %s\n", event, state_machine.state);
    }
}

int main() {
    simulate_network_connection();
    return 0;
}