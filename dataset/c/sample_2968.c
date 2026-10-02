#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char state[20];
} StateMachine;

void StateMachine_init(StateMachine *self) {
    strcpy(self->state, "initial");
}

void StateMachine_transition(StateMachine *self, const char *event) {
    if (strcmp(self->state, "initial") == 0) {
        if (strcmp(event, "connect") == 0) {
            strcpy(self->state, "connected");
        } else {
            strcpy(self->state, "error");
        }
    } else if (strcmp(self->state, "connected") == 0) {
        if (strcmp(event, "disconnect") == 0) {
            strcpy(self->state, "disconnected");
        } else if (strcmp(event, "data") == 0) {
            strcpy(self->state, "processing");
        } else {
            strcpy(self->state, "error");
        }
    } else if (strcmp(self->state, "processing") == 0) {
        if (strcmp(event, "complete") == 0) {
            strcpy(self->state, "connected");
        } else {
            strcpy(self->state, "error");
        }
    } else if (strcmp(self->state, "disconnected") == 0) {
        if (strcmp(event, "connect") == 0) {
            strcpy(self->state, "connected");
        } else {
            strcpy(self->state, "error");
        }
    } else if (strcmp(self->state, "error") == 0) {
        if (strcmp(event, "reset") == 0) {
            strcpy(self->state, "initial");
        } else {
            strcpy(self->state, "error");
        }
    }
}

const char* event_generator() {
    const char* events[] = {"connect", "disconnect", "data", "complete", "reset"};
    return events[rand() % 5];
}

void process_events(StateMachine *state_machine) {
    while (1) {
        const char* event = event_generator();
        StateMachine_transition(state_machine, event);
    }
}

int main() {
    srand(time(NULL));
    StateMachine state_machine;
    StateMachine_init(&state_machine);
    process_events(&state_machine);
    return 0;
}