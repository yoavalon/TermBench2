#include <stdio.h>
#include <string.h>

typedef struct {
    char state[10];
} NetworkState;

void NetworkState_init(NetworkState *self) {
    strcpy(self->state, "idle");
}

char* NetworkState_transition(NetworkState *self, const char* event) {
    if (strcmp(self->state, "idle") == 0 && strcmp(event, "connect") == 0) {
        strcpy(self->state, "active");
    } else if (strcmp(self->state, "active") == 0 && strcmp(event, "disconnect") == 0) {
        strcpy(self->state, "idle");
    } else if (strcmp(self->state, "active") == 0 && strcmp(event, "data") == 0) {
        strcpy(self->state, "processing");
    } else if (strcmp(self->state, "processing") == 0 && strcmp(event, "complete") == 0) {
        strcpy(self->state, "active");
    } else if (strcmp(self->state, "processing") == 0 && strcmp(event, "error") == 0) {
        strcpy(self->state, "active");
    }
    return self->state;
}

typedef struct {
    const char* events[5];
    int index;
} EventGenerator;

void EventGenerator_init(EventGenerator *self) {
    self->events[0] = "connect";
    self->events[1] = "data";
    self->events[2] = "complete";
    self->events[3] = "error";
    self->events[4] = "disconnect";
    self->index = 0;
}

const char* EventGenerator_get_event(EventGenerator *self) {
    const char* event = self->events[self->index];
    self->index = (self->index + 1) % 5;
    return event;
}

typedef struct {
    NetworkState state_machine;
    EventGenerator event_generator;
} NetworkSystem;

void NetworkSystem_init(NetworkSystem *self) {
    NetworkState_init(&self->state_machine);
    EventGenerator_init(&self->event_generator);
}

void NetworkSystem_run(NetworkSystem *self) {
    while (1) {
        const char* event = EventGenerator_get_event(&self->event_generator);
        const char* new_state = NetworkState_transition(&self->state_machine, event);
        printf("Event: %s, New State: %s\n", event, new_state);
    }
}

int main() {
    NetworkSystem network_system;
    NetworkSystem_init(&network_system);
    NetworkSystem_run(&network_system);
    return 0;
}