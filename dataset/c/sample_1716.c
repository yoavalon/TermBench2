#include <stdio.h>
#include <string.h>

typedef struct {
    char state[20];
} NetworkState;

void NetworkState_init(NetworkState *self) {
    strcpy(self->state, "DISCONNECTED");
}

void NetworkState_transition(NetworkState *self, const char *event) {
    if (strcmp(self->state, "DISCONNECTED") == 0 && strcmp(event, "CONNECT") == 0) {
        strcpy(self->state, "CONNECTED");
    } else if (strcmp(self->state, "CONNECTED") == 0 && strcmp(event, "DATA_RECEIVED") == 0) {
        strcpy(self->state, "DATA_PROCESSING");
    } else if (strcmp(self->state, "DATA_PROCESSING") == 0 && strcmp(event, "DATA_PROCESSED") == 0) {
        strcpy(self->state, "CONNECTED");
    } else if (strcmp(self->state, "CONNECTED") == 0 && strcmp(event, "DISCONNECT") == 0) {
        strcpy(self->state, "DISCONNECTED");
    }
}

typedef struct {
    const char *events[4];
    int index;
} NetworkEventGenerator;

void NetworkEventGenerator_init(NetworkEventGenerator *self) {
    self->events[0] = "CONNECT";
    self->events[1] = "DATA_RECEIVED";
    self->events[2] = "DATA_PROCESSED";
    self->events[3] = "DISCONNECT";
    self->index = 0;
}

const char *NetworkEventGenerator_next_event(NetworkEventGenerator *self) {
    const char *event = self->events[self->index];
    self->index = (self->index + 1) % 4;
    return event;
}

typedef struct {
    NetworkState state_machine;
    NetworkEventGenerator event_generator;
} NetworkSystem;

void NetworkSystem_init(NetworkSystem *self) {
    NetworkState_init(&self->state_machine);
    NetworkEventGenerator_init(&self->event_generator);
}

void NetworkSystem_run(NetworkSystem *self) {
    while (1) {
        const char *event = NetworkEventGenerator_next_event(&self->event_generator);
        NetworkState_transition(&self->state_machine, event);
    }
}

int main() {
    NetworkSystem system;
    NetworkSystem_init(&system);
    NetworkSystem_run(&system);
    return 0;
}