#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char state[10];
    int connection;
} NetworkState;

void NetworkState_init(NetworkState *self) {
    strcpy(self->state, "idle");
    self->connection = 0;
}

void NetworkState_transition(NetworkState *self, const char *event) {
    if (strcmp(self->state, "idle") == 0 && strcmp(event, "connect") == 0) {
        strcpy(self->state, "connected");
        self->connection = 1;
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "disconnect") == 0) {
        strcpy(self->state, "idle");
        self->connection = 0;
    } else if (strcmp(self->state, "idle") == 0 && strcmp(event, "error") == 0) {
        strcpy(self->state, "error");
    } else if (strcmp(self->state, "connected") == 0 && strcmp(event, "error") == 0) {
        strcpy(self->state, "error");
    } else if (strcmp(self->state, "error") == 0 && strcmp(event, "recover") == 0) {
        strcpy(self->state, "idle");
    }
}

typedef struct {
    const char *events[4];
    int index;
} EventGenerator;

void EventGenerator_init(EventGenerator *self) {
    self->events[0] = "connect";
    self->events[1] = "disconnect";
    self->events[2] = "error";
    self->events[3] = "recover";
    self->index = 0;
}

const char *EventGenerator_next_event(EventGenerator *self) {
    const char *event = self->events[self->index];
    self->index = (self->index + 1) % 4;
    return event;
}

typedef struct {
    NetworkState state_machine;
    EventGenerator event_source;
} NetworkSystem;

void NetworkSystem_init(NetworkSystem *self) {
    NetworkState_init(&self->state_machine);
    EventGenerator_init(&self->event_source);
}

void NetworkSystem_run(NetworkSystem *self) {
    while (1) {
        const char *event = EventGenerator_next_event(&self->event_source);
        NetworkState_transition(&self->state_machine, event);
        printf("Event: %s, State: %s\n", event, self->state_machine.state);
    }
}

int main() {
    NetworkSystem system;
    NetworkSystem_init(&system);
    NetworkSystem_run(&system);
    return 0;
}