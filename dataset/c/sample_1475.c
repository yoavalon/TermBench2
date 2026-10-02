#include <stdio.h>
#include <string.h>

typedef struct {
    char state[20];
    char *connection;
} StateMachine;

void StateMachine_init(StateMachine *self) {
    strcpy(self->state, "idle");
    self->connection = NULL;
}

void StateMachine_transition(StateMachine *self, const char *event) {
    if (strcmp(self->state, "idle") == 0 && strcmp(event, "connect") == 0) {
        strcpy(self->state, "connected");
        self->connection = "active";
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "disconnect") == 0) {
        strcpy(self->state, "idle");
        self->connection = NULL;
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "data") == 0) {
        strcpy(self->state, "processing");
    } else if (strcmp(self->state, "processing") == 0 && strcmp(event, "complete") == 0) {
        strcpy(self->state, "connected");
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "error") == 0) {
        strcpy(self->state, "error");
        self->connection = NULL;
    } else if (strcmp(self->state, "error") == 0 && strcmp(event, "reset") == 0) {
        strcpy(self->state, "idle");
    }
}

typedef struct {
    const char *events[6];
    int index;
} EventGenerator;

void EventGenerator_init(EventGenerator *self) {
    self->events[0] = "connect";
    self->events[1] = "disconnect";
    self->events[2] = "data";
    self->events[3] = "complete";
    self->events[4] = "error";
    self->events[5] = "reset";
    self->index = 0;
}

const char *EventGenerator_generate(EventGenerator *self) {
    const char *event = self->events[self->index];
    self->index = (self->index + 1) % 6;
    return event;
}

void main() {
    StateMachine machine;
    EventGenerator generator;
    StateMachine_init(&machine);
    EventGenerator_init(&generator);
    for (int i = 0; i < 20; i++) {
        const char *event = EventGenerator_generate(&generator);
        StateMachine_transition(&machine, event);
        printf("Event: %s, State: %s, Connection: %s\n", event, machine.state, machine.connection ? machine.connection : "None");
    }
}